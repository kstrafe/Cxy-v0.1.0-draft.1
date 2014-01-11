#include  "File.hpp"
#include  <iostream>
#include  <stdexcept>


File::File(const std::string &file)
:
    m_file(file)
{}


void File::process()
{
    read();
    include();
    parse();
    interpret();
}


void File::read()
{
    m_content = ttl::file2str(m_file);
}


void File::include()
{
    static constexpr const sti REMAINING_LAST_TWO = 2, DELIMITING_CHAR = 1;

    sti start = m_content.find("#cxy <");
    while (start != m_content.npos)
    {
        ttl::ScopedFunction retry_find
        (
            [&start, this]()
            {
                start = m_content.find("#cxy <");
            }
        );

        sti end = start + (sizeof("#cxy <") / sizeof(char)) - DELIMITING_CHAR;

        sti ending = end, length = 0;
        for (; m_content[ending] != '>'; ++ending, ++length);
        std::string include_name(m_content.substr(end, length));

        // Need to remove the "#cxy <file>" string
        m_content.erase(start, (ending - start) + REMAINING_LAST_TWO);
        m_content.insert(start, ttl::file2str(include_name)); // Place the file there instead
    }
}


void File::parse()
{
    static constexpr const sti REMAINING_LAST = 1, DELIMITING_CHAR = 1, END_OF_EXPRESSION = 8;

    sti start = m_content.find("#cxy start");
    while (start != m_content.npos)
    {
        ttl::ScopedFunction retry_find
        (
            [&start, this]()
            {
                start = m_content.find("#cxy start");
            }
        );

        sti end = start + sizeof("#cxy start") / sizeof(char) - DELIMITING_CHAR;
        sti stop = parseStatements(end);
        // Remove "#cxy start - X - #cxy stop" sequence.
        m_content.erase(start, (stop - start + END_OF_EXPRESSION) + REMAINING_LAST);
    }
}


void File::interpret()
{
    std::fstream argrep("argument_representation", std::ios::out | std::ios::trunc);
    for (auto &x : m_statements)
    {
        argrep << x << "\n";
    }


    for (sti i = 0; i < m_statements.size(); ++i)
    {
        std::string &s = m_statements[i];
//        std::cout << "NEXT COMMAND: " << s << std::endl;
        if (s == "rep")
            rep(i);
        else if (s == "cnt")
            cnt(i);
        else if (s == "show")
            show(i);
        else if (s == "print" || s == "echo")
            print(i);
        else if (s == "if")
            if_statement(i);
        else if (s == "goto")
            goto_statement(i);
        else if (s == "lt")
            lt(i);
        else if (s == "st")
            st(i);
        else if (s == "inc")
            inc(i);
        else if (s[0] != ':' && s != "begin")// See it as "raw data specifier"
            data(i);
    }
    for (auto &x : m_statements)
    {
//        std::cout << x << std::endl;
    }
    m_statements.clear();
}


File::sti File::parseStatements(sti position)
{
    if (m_content[position++] == '\n')
    {
        while (true)
        {
            std::string statement(std::move(getNextArgument(m_content, position)));
            if (statement.size() == 0)
            {
                return position;
            }
            else
            {
                m_statements.emplace_back(std::move(statement));
            }
        }
    }
    else
    {
        throw std::runtime_error("#cxy start must be superseded by a new line.");
    }
    return position;
}


std::string File::getNextArgument(const std::string &str, sti &position)
{
    static constexpr const sti FIRST = 1, LAST = 1;

    std::string nruter;
    sti eos; // end of statement
    while (position < str.size())
    {
        if (std::isalpha(str[position]) || std::isdigit(str[position]))
        {
            for (eos = position; eos < str.size() && (std::isalpha(str[eos]) || std::isdigit(str[position])); ++eos);
            nruter = str.substr(position, eos - position);
            position = eos + 1;
            if (nruter == "#cxy stop")
                return "";
            return nruter;
        }
        else if (str[position] == '\"')
        {
            for (eos = position + 1; eos < str.size() && str[eos] != '\"'; ++eos);
            nruter = str.substr(position + FIRST /* First is a " */, eos - position - LAST /* Last is a " */);
            position = eos + 1;
            return nruter;
        }
        else if (str[position] == m_parser_sign)
        {
            ++position;
            return "";
        }
        else if (str[position] == ':')
        {
            for (eos = position + 1; eos < str.size() && std::isalpha(str[eos]); ++eos);
            nruter = str.substr(position, eos - position);
            position = eos + 1;
//            std::cout << "NRUTER: " << nruter << '\'';
            return nruter;
        }
        ++position;
    }
    return nruter;
}


bool File::isInvalidStatementCharacter(char argument) const
{
    switch (argument)
    {
        default: return true;
        case ' ':
        case '"':
        case '#':
            return false;
    }
}


void File::rep(sti &i)
{
    sti occurrence = m_content.find(m_statements[++i]);
    while (occurrence != m_content.npos)
    {
        m_content.erase(occurrence, m_statements[i].size());
        m_content.insert(occurrence, m_statements[i + 1]);
        occurrence = m_content.find(m_statements[i]);
    }
    ++i;
}


void File::cnt(sti &i)
{
    std::string &tosrch(m_statements[++i]);
    sti occurrence = 0, last = 0;
    while ((last = m_content.find(tosrch, ++last)) != m_content.npos)
    {
        ++occurrence;
    }
    m_statements[i] = std::to_string(occurrence);
//    m_content.insert(0, std::to_string(occurrence));
}


void File::show(sti &i)
{
    std::cout << m_data[m_statements[++i]] << std::endl;
//    m_content.insert(0, toprnt);
}


void File::print(sti &i)
{
    std::string &toprnt(m_statements[++i]);
    std::cout << toprnt << std::endl;
//    m_content.insert(0, toprnt);
}


void File::if_statement(sti &i)
{
    // Sum up all the statements:
//    sti begin = ++i, end = begin;
//    for (; end < m_statements.size(); ++end)
//    {
//        if (m_statements[end] == "begin")
//            break;
//
//    }

    // from [begin, end), we must evaluate statements:

    std::string &f(m_statements[++i]);
    std::string &b(m_statements[++i]);

//    std::cout << m_data[f] << ">" << m_data[b] << std::endl;

    if (std::atoi(m_data[f].data()) > std::atoi(m_data[b].data()))
    {
//        std::cout << "Condition executes\n";
        return;
    }
    else
    {
//        std::cout << "Condition does not execute\n";
        for (sti z = i; z < m_statements.size(); ++z)
        {
            if (m_statements[z] != "end")
                ++i;
            else
                break;
        }
    }


//    if (nxt == "true")
//    {
//        return;
//    }
//    else
//    {
//        for (auto &x : m_statements)
//        {
//            if (x != "end")
//                ++i;
//            else
//                break;
//        }
//    }
}


void File::goto_statement(sti &i)
{
    std::string &jumpto(m_statements[++i]);
//    std::cout << "Before changes: " << m_statements[i];
    for (sti p = 0; p < m_statements.size(); ++p)
    {
        if (m_statements[p] == ":" + jumpto && m_statements[p - 1] != "goto")
        {
//            std::cout << "\tAfter change: " << m_statements[p] << std::endl;
            i = p;
            return;
        }
    }
}


void File::lt(sti &i)
{
    std::string toprnt(std::move(m_statements[++i]));
    m_content.insert(0, toprnt);
}


void File::st(sti &i)
{
    std::string toprnt(std::move(m_statements[++i]));
    m_content.insert(0, toprnt);
}


void File::inc(sti &i)
{
    int num = std::atoi(m_data[m_statements[++i]].data());
    m_data[m_statements[i]] = std::to_string(num + 1);
}


void File::data(sti &i)
{
    m_data[m_statements[i]] = m_statements[i + 1];
    ++i;
}


std::ostream &operator<<(std::ostream &os, const File &file)
{
    os << file.m_content;
    return os;
}










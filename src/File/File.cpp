#include  "File.hpp"
#include  <iostream>
#include  <stdexcept>


File::File(const std::string &file)
:
    m_file(file)
{
    m_data["cnt"].emplace_back("0");
    m_data["eq"].emplace_back("0");
    m_data["neq"].emplace_back("0");
    m_data["lt"].emplace_back("0");
    m_data["st"].emplace_back("0");
    m_data["ptr"].emplace_back("0");
    m_data["mrk"].emplace_back("0");
    m_data["size"].emplace_back("0");
    m_data["next"].emplace_back("");
    m_data["prev"].emplace_back("");
    m_data["and"].emplace_back("0");
    m_data["or"].emplace_back("0");
    m_data["xor"].emplace_back("0");
    m_data["not"].emplace_back("0");
    m_data["capt"].emplace_back("");
}


void File::process()
{
    read();
    include();
    parse();
    interpret();
    execute();
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
        std::string include_name(m_content.substr(end, length)); // Get include file's name

        m_content.erase(start, (ending - start) + REMAINING_LAST_TWO); // Need to remove the "#cxy <file>" string

        // INCLUDE AT START
//        m_content.insert(start, ttl::file2str(include_name)); // Place the file there instead
        // INCLUDE AT END
        m_content.insert(m_content.size(), ttl::file2str(include_name));
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

}


void File::execute()
{
    std::fstream argrep("argument_representation", std::ios::out | std::ios::trunc);
    for (auto &x : m_statements)
    {
        argrep << x << "\n";
    }


    for (sti i = 0; i < m_statements.size(); ++i)
    {
//        ttl::sleep(1);
        std::string &s = m_statements[i];
        std::cout << "NEXT COMMAND: '" << s << "'" << std::endl;
        if (s == "ins")
            ins(i);
        else if (s == "del")
            del(i);
        else if (s == "bck")
            bck(i);
        else if (s == "cnt")
            cnt(i);
        else if (s == "find")
            find(i);
        else if (s == "size")
            size(i);
        else if (s == "capt")
            capt(i);
        else if (s == "trim")
            trim(i);
        else if (s == "cnc")
            cnc(i);
        else if (s == "show")
            show(i);
        else if (s == "if")
            if_statement(i);
        else if (s == "goto")
            goto_statement(i);
        else if (s == "eq")
            eq(i);
        else if (s == "neq")
            neq(i);
        else if (s == "lt")
            lt(i);
        else if (s == "st")
            st(i);
        else if (s == "inc")
            inc(i);
        else if (s == "dec")
            dec(i);
        else if (s == "add")
            add(i);
        else if (s == "sub")
            sub(i);
        else if (s == "push")
            push(i);
        else if (s == "pop")
            pop(i);
        else if (s == "mov")
            mov(i);
        else if (s == "cp")
            cp(i);
        else if (s == "next")
            next(i);
        else if (s == "prev")
            prev(i);
        else if (s == "and")
            and_statement(i);
        else if (s == "or")
            or_statement(i);
        else if (s == "xor")
            xor_statement(i);
        else if (s == "not")
            not_statement(i);
        else if (s[0] != ':' && s != "stop")
            std::cout << "NO HANDLER\n";
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
        if (str[position] == '/' && str[position + 1] == '/')
        {
            for (; position < str.size(); ++position)
            {
                if (str[position] == '\n')
                    break;
            }
        }
        else if (std::isalpha(str[position]) || std::isdigit(str[position]) || str[position] == '*')
        {
            for (eos = position; eos < str.size() && (std::isalpha(str[eos]) || std::isdigit(str[position]) || str[position] == '*'); ++eos);
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


bool File::isValidStatementCharacter(char argument) const
{
    switch (argument)
    {
        default: return true;
        case '*': // Dereferencing
        case '{': // Scope begin
        case '}': // Scope end
            return true;
    }
}


File::sti File::getNumber(const std::string &str)
{
    return std::atoi(m_data[str].back().data());
}


std::string &File::getData(const std::string &str)
{
    return m_data[str].back();
}


void File::ins(sti &i)
{
    const sti pos = getNumber("ptr");

    m_content.erase
    (
        pos,
        getNumber("mrk") - pos
    );

    m_content.insert(pos, getData(m_statements[++i]));
    getData("ptr") = std::to_string(getNumber("ptr") + getData(m_statements[i]).size());
    getData("mrk") = getData("ptr");
}


void File::del(sti &i)
{
    sti
        ptr = getNumber("ptr"),
        mrk = getNumber("mrk");

    if (ptr == mrk)
        ++mrk;
    m_content.erase(ptr, mrk - ptr);

    getData("mrk") = getData("ptr");
}


void File::bck(sti &i)
{
    const
        sti ptr = getNumber("ptr"),
        mrk = getNumber("mrk");

    if (ptr == mrk)
    {
        if (ptr > 0)
        {
            m_content.erase(ptr - 1, 1);
            m_data["ptr"].back() = std::to_string(ptr - 1);
        }
        else
        {
            // Backspace must be ignored
        }
    }
    else
    {
        m_content.erase(ptr, mrk - ptr);
    }
    getData("mrk") = getData("ptr");
}


void File::cnt(sti &i)
{
    const
        sti ptr = getNumber("ptr"),
        mrk = getNumber("mrk");

    std::string &tosrch(getData(m_statements[++i]));
    sti occurrence = 0, last = ptr - (ptr > 0 ? 1 : 0);

    if (ptr == mrk) // Unrestricted area (from pointer to file end)
    {
        while ((last = m_content.find(tosrch, (ptr > 0 ? ++last : last))) != m_content.npos)
            ++occurrence;
    }
    else // Restricted area (from pointer till marker)
    {
        while (((last = m_content.find(tosrch, (ptr > 0 ? ++last : last))) != m_content.npos) && ((last + tosrch.size() - 1) < marker))
            ++occurrence;
    }
    getData("cnt") = std::to_string(occurrence);
}


void File::find(sti &i)
{
    sti ptr = getNumber("ptr"),
    mrk = getNumber("mrk");

    std::string &tosrch(getData(m_statements[++i]));
    sti occurrence = 0, last = ptr - (ptr > 0 ? 1 : 0);

    if (ptr == mrk) // Unrestricted area (from pointer to file end)
    {
        if ((last = m_content.find(tosrch, (ptr > 0 ? ++last : last))) != m_content.npos)
            ptr = last;
        getData("mrk") = std::to_string(last + tosrch.size() - (ptr > 0 ? 0 : 1));
        getData("ptr") = std::to_string(ptr);
    }
    else // Restricted area (from pointer till marker)
    {
        if ((last = m_content.find(tosrch, (ptr > 0 ? ++last : last))) != m_content.npos)
        {
            if (last + tosrch.size() < mrk)
            {
                ptr = last;
                getData("mrk") = std::to_string(last + tosrch.size());
                getData("ptr") = std::to_string(ptr);
            }
        }
    }
}


void File::size(sti &i)
{
    sti si = getData(m_statements[++i]).size();
    getData("size") = std::to_string(si);
}


void File::capt(sti &i)
{
    m_data["capt"].back() = m_content.substr
    (
        getNumber("ptr"),
        getNumber("mrk") - getNumber("ptr")
    );
}


void File::trim(sti &i)
{
    std::string &r( getData(m_statements[++i]) );
    r.erase(0, r.find_first_not_of(' '));
    for (sti i = r.size() - 1; i > 0; --i)
    {
        if (r[i] == ' ')
        {
            r.pop_back();
        }
    }
    if (r.size() == 1 && r[0] == ' ')
        r.pop_back();
}


void File::cnc(sti &i)
{
    std::string &r( getData(m_statements[++i]) );
    r.append( getData(m_statements[++i]) );
}


void File::show(sti &i)
{
    std::cout << getData(m_statements[++i]) << std::endl;
}


void File::if_statement(sti &i)
{
    std::string &nxt(getData(m_statements[++i]));
    if (nxt.size() > 0 && nxt[0] == '1')
    {
        return;
    }
    else // skip the entire if
    {
        sti nests = 0; // Nests: if inside if; we need to keep track of openers vs closers
        ++i;
        for (; i < m_statements.size(); ++i)
        {
            if (m_statements[i] != "stop")
            {
                if (m_statements[i] == "if")
                {
                    ++nests;
                }
            }
            else
            {
                if (nests == 0) // This is the stop that corresponds with our initial if
                {
                    break;
                }
                else
                {
                    --nests;
                }
            }
        }
    }
}


void File::goto_statement(sti &i)
{
    std::string &jumpto(m_statements[++i]);
    for (sti p = 0; p < m_statements.size(); ++p)
    {
        if (m_statements[p] == ":" + jumpto && m_statements[p - 1] != "goto")
        {
            i = p;
            return;
        }
    }
}


void File::eq(sti &i)
{
    getData("eq") = (getData(m_statements[i + 1]) == getData(m_statements[i + 2]) ? "1" : "0");
    i += 2;
}


void File::neq(sti &i)
{
    getData("neq") = (getData(m_statements[i + 1]) != getData(m_statements[i + 2]) ? "1" : "0");
    i += 2;
}


void File::lt(sti &i)
{
    int a = std::atoi(m_data[m_statements[i + 1]].back().data()),
        b = std::atoi(m_data[m_statements[i + 2]].back().data());
    m_data["lt"].back() = (a > b ? "1" : "0");
    i += 2;
}


void File::st(sti &i)
{
    int a = std::atoi(m_data[m_statements[i + 1]].back().data()),
        b = std::atoi(m_data[m_statements[i + 2]].back().data());
    m_data["st"].back() = (a < b ? "1" : "0");
    i += 2;
}


void File::inc(sti &i)
{
    int num = std::atoi(m_data[m_statements[++i]].back().data());
    m_data[m_statements[i]].back() = std::to_string(num + 1);
}


void File::dec(sti &i)
{
    int num = std::atoi(m_data[m_statements[++i]].back().data());
    m_data[m_statements[i]].back() = std::to_string(num - 1);
}


void File::add(sti &i)
{
    int num = std::atoi(m_data[m_statements[++i]].back().data());
    m_data[m_statements[i]].back() = std::to_string(num + std::atoi(m_data[m_statements[i + 1]].back().data()));
    ++i;
}


void File::sub(sti &i)
{
    int num = std::atoi(m_data[m_statements[++i]].back().data());
    m_data[m_statements[i]].back() = std::to_string(num - std::atoi(m_data[m_statements[i + 1]].back().data()));
    ++i;
}


void File::push(sti &i)
{
    if (m_data[m_statements[i + 1]].size() > 0)
        m_data[m_statements[i + 1]].emplace_back(m_data[m_statements[i + 1]].back());
    else
        m_data[m_statements[i + 1]].emplace_back("");
    ++i;
}


void File::pop(sti &i)
{
    m_data[m_statements[++i]].pop_back();
    if (m_data[m_statements[i]].size() == 0)
    {
        m_data.erase(m_statements[i]);
    }
}


void File::mov(sti &i)
{
    getData(m_statements[i + 1]) = getData(m_statements[i + 2]);
    i += 2;
}


void File::cp(sti &i)
{
    m_data[m_statements[i + 1]].back() = m_statements[i + 2];
    i += 2;
}

void File::and_statement(sti &i)
{
    m_data["and"].back() =
    (
        (std::atoi(m_data[m_statements[i + 1]].back().data())
        && std::atoi(m_data[m_statements[i + 2]].back().data()))
        ?
            "true"
            :
            "false"
    );

    i += 2;
}

void File::or_statement(sti &i)
{
    m_data["or"].back() =
        (std::atoi(m_data[m_statements[i + 1]].back().data())
        || std::atoi(m_data[m_statements[i + 2]].back().data())
         ?
            "true"
            :
            "false"
    );

    i += 2;
}

void File::xor_statement(sti &i)
{
    m_data["xor"].back() =
    (
        std::atoi(m_data[m_statements[i + 1]].back().data())
        != std::atoi(m_data[m_statements[i + 2]].back().data())
        ?
            "true"
            :
            "false"
    );

    i += 2;
}

void File::not_statement(sti &i)
{
    m_data["not"].back() = std::to_string
    (
        !std::atoi(m_data[m_statements[i + 1]].back().data())
    );

    ++i;
}


void File::next(sti &i)
{
    marker = std::atoi(m_data["mrk"].back().data()) + 1;
    m_data["mrk"].back() = std::to_string(marker);
    m_data["next"].back() = m_content[marker];
}


void File::prev(sti &i)
{
    sti pointer = std::atoi(m_data["ptr"].back().data()) - 1;
    m_data["ptr"].back() = std::to_string(pointer);
    m_data["prev"].back() = m_content[pointer];
}


std::ostream &operator<<(std::ostream &os, const File &file)
{
    os << file.m_content;
    return os;
}









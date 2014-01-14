// Headers
#include "File.hpp"


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
        else if (s == "drf")
            drf(i);
        else if (s == "rdf")
            rdf(i);
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
        else if (s == "cpy")
            cpy(i);
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

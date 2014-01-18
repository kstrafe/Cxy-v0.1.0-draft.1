// Headers
#include "File.hpp"


void File::interpret()
{
    m_runstate = Runstate::Interpret;
//    std::fstream argrep("argument_representation", std::ios::out | std::ios::trunc);
//    for (auto &x : m_instructions)
//    {
//        argrep << x << "\n";
//    }


    for (Sti_t i = 0; i < m_instructions.size(); ++i)
    {
//        ttl::sleep(1);
        String_t &s = m_instructions[i];
//        std::cout << "NEXT COMMAND: '" << s << "'" << std::endl;
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
        else if (s == "swap")
            swap(i);
        else if (s == "dir")
            dir(i);
        else if (s == "odir")
            odir(i);
        else if (s == "isdr")
            isdr(i);
        else if (s == "extp")
            extp(i);
        else if (s == "updr")
            updr(i);
        else if (s == "fln")
            fln(i);
        else if (s == "adir")
            adir(i);
        else if (s == "show")
            show(i);
        else if (s == "reset")
            reset(i);
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
    for (auto &x : m_instructions)
    {
//        std::cout << x << std::endl;
    }
    m_instructions.clear();

}

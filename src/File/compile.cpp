// Headers
#include "File.hpp"


void File::compile()
{
    std::vector<Instruction> instructions;

    std::function<void(Instruction)> a
    (
        [&instructions](Instruction i)
        {
            instructions.emplace_back(i);
        }
    );

    std::map<String_t, Sti_t> jump_table;
    std::map<String_t, Sti_t> symbol_table;

    Sti_t max_jump = 0;
    Sti_t max_symbol = 0;

    // Translate to bytecode:
    for (Sti_t i = 0; i < m_instructions.size(); ++i)
    {
        String_t &s = m_instructions[i];
        if (s == "ins")
            a(Instruction::ins);
        else if (s == "del")
            a(Instruction::del);
        else if (s == "bck")
            a(Instruction::bck);
        else if (s == "cnt")
            a(Instruction::cnt);
        else if (s == "find")
            a(Instruction::find);
        else if (s == "size")
            a(Instruction::size);
        else if (s == "capt")
            a(Instruction::capt);
        else if (s == "trim")
            a(Instruction::trim);
        else if (s == "cnc")
            a(Instruction::cnc);
        else if (s == "drf")
            a(Instruction::drf);
        else if (s == "rdf")
            a(Instruction::rdf);
        else if (s == "swap")
            a(Instruction::swap);
        else if (s == "dir")
            a(Instruction::dir);
        else if (s == "odir")
            a(Instruction::odir);
        else if (s == "isdr")
            a(Instruction::isdr);
        else if (s == "extp")
            a(Instruction::extp);
        else if (s == "updr")
            a(Instruction::updr);
        else if (s == "fln")
            a(Instruction::fln);
        else if (s == "adir")
            a(Instruction::adir);
        else if (s == "show")
            a(Instruction::show);
        else if (s == "reset")
            a(Instruction::reset);
        else if (s == "if")
            a(Instruction::if_statement);
        else if (s == "goto")
            a(Instruction::goto_statement);
        else if (s == "eq")
            a(Instruction::eq);
        else if (s == "neq")
            a(Instruction::neq);
        else if (s == "lt")
            a(Instruction::lt);
        else if (s == "st")
            a(Instruction::st);
        else if (s == "inc")
            a(Instruction::inc);
        else if (s == "dec")
            a(Instruction::dec);
        else if (s == "add")
            a(Instruction::add);
        else if (s == "sub")
            a(Instruction::sub);
        else if (s == "push")
            a(Instruction::push);
        else if (s == "pop")
            a(Instruction::pop);
        else if (s == "mov")
            a(Instruction::mov);
        else if (s == "cpy")
            a(Instruction::cpy);
        else if (s == "next")
            a(Instruction::next);
        else if (s == "prev")
            a(Instruction::prev);
        else if (s == "and")
            a(Instruction::and_statement);
        else if (s == "or")
            a(Instruction::or_statement);
        else if (s == "xor")
            a(Instruction::xor_statement);
        else if (s == "not")
            a(Instruction::not_statement);
        else if (s[0] != ':' && s != "stop")
        {

        }
    }
}

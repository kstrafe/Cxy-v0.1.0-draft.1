// Headers
#include "File.hpp"
#include <chrono>


void File::compile()
{
    std::cout << "Initializing variables..." << std::endl;

    std::vector<String_t> instructions;

    std::function<void(Instruction)> a
    (
        [&instructions](Instruction i)
        {
            String_t tmp;
            tmp.push_back(static_cast<Instruction_enum_t>(i));
            instructions.emplace_back(tmp);
        }
    );

    std::function<void(Sti_t)> b
    (
        [&instructions](Sti_t i)
        {
            String_t tmp;
            tmp.push_back(static_cast<Instruction_enum_t>(i));
            instructions.emplace_back(tmp);
        }
    );

    std::map<String_t, Sti_t> jump_table;
    std::map<String_t, Sti_t> symbol_table;

    Sti_t jump_symbols = 0;
    Sti_t max_symbol = static_cast<Sti_t>(Instruction::END); // Registers have their own space


    // Generate jump table
    std::cout << "Generating jump table..." << std::endl;
    for (Sti_t i = 0; i < m_instructions.size(); ++i)
    {
        String_t &s(m_instructions[i]);
        if (s[0] == ':')
        {
            jump_table[s.substr(1)] = i - jump_symbols++;
        }
    }
    std::cout << "Generated symbol table succesfully" << std::endl;

    // Generate symbol table
    std::cout << "Generating symbol table..." << std::endl;
    for (Sti_t i = 0; i < m_instructions.size(); ++i)
    {
        String_t &s(m_instructions[i]);
        if (s == "ins")
            ;
        else if (s == "del")
            ;
        else if (s == "bck")
            ;
        else if (s == "cnt")
            ;
        else if (s == "find")
            ;
        else if (s == "size")
            ;
        else if (s == "capt")
            ;
        else if (s == "trim")
            ;
        else if (s == "cnc")
            ;
        else if (s == "drf")
            ;
        else if (s == "rdf")
            ;
        else if (s == "swap")
            ;
        else if (s == "dir")
            ;
        else if (s == "odir")
            ;
        else if (s == "isdr")
            ;
        else if (s == "extp")
            ;
        else if (s == "updr")
            ;
        else if (s == "fln")
            ;
        else if (s == "adir")
            ;
        else if (s == "show")
            ;
        else if (s == "reset")
            ;
        else if (s == "if")
            ;
        else if (s == "goto")
            ;
        else if (s == "eq")
            ;
        else if (s == "neq")
            ;
        else if (s == "lt")
            ;
        else if (s == "st")
            ;
        else if (s == "inc")
            ;
        else if (s == "dec")
            ;
        else if (s == "add")
            ;
        else if (s == "sub")
            ;
        else if (s == "push")
            ;
        else if (s == "pop")
            ;
        else if (s == "mov")
            ;
        else if (s == "cpy")
            ;
        else if (s == "next")
            ;
        else if (s == "prev")
            ;
        else if (s == "and")
            ;
        else if (s == "or")
            ;
        else if (s == "xor")
            ;
        else if (s == "not")
            ;
        else if (s == "stop")
            ;
        else // Yay, it's a symbol!
        {
            if (true || (i >= 2 && m_instructions[i - 2] != "if"))
            {
                auto x = symbol_table.find(s);
                if (x == symbol_table.end())
                {
                    symbol_table[s] = max_symbol++;
                }
            }
        }
    }
    std::cout << "Finished generating symbol table succesfully" << std::endl;


    // Translate to bytecode:
    std::cout << "Translating to Cxy bytecode..." << std::endl;
    for (Sti_t i = 0; i < m_instructions.size(); ++i)
    {
        String_t &s(m_instructions[i]);

        if (s[0] == ':')
            ;
        else if (s == "ins")
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
        else
        {
            std::string tmp;
            if (i >= 2)
                tmp = *(instructions.end() - 2);

            if
            (
                i > 0
                &&
                (
                    (instructions.back()[0] == static_cast<Instruction_enum_t>(Instruction::goto_statement))
                    ||
                    (tmp[0] == static_cast<Instruction_enum_t>(Instruction::if_statement))
                )
            )
            {
                b(jump_table[s]);
            }
            else if (i < 2 || (i >= 2 && static_cast<Instruction_enum_t>(instructions[i - 2][0]) != static_cast<Instruction_enum_t>(Instruction::cpy)))
            {
                std::cout << "Translating " << s << " into: " << symbol_table[s] << "\n";
                b(symbol_table[s]);
            }
            else
            {
                std::cout << "Raw instruction: " << s << std::endl;
                instructions.push_back(s);
            }
        }
    }
    std::cout << "Translation complete" << std::endl;

    std::fstream st("compiled.cxy", std::ios::out);
    for (auto &x : instructions)
        st << x << '\n';

    std::swap(instructions, m_instructions);
}

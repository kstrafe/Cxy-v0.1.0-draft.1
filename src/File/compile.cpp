// Headers
#include "File.hpp"
#include <chrono>


void File::compile()
{
    std::cout << "Initializing variables..." << std::endl;

    std::vector<String_t> instructions;

    std::function<void(Symbol)> a
    (
        [&instructions](Symbol i)
        {
            String_t tmp;
            tmp.push_back(static_cast<Symbol_enum_t>(i));
            instructions.emplace_back(tmp);
        }
    );

    std::function<void(Sti_t)> b
    (
        [&instructions](Sti_t i)
        {
            String_t tmp;
            tmp.push_back(static_cast<Symbol_enum_t>(i));
            instructions.emplace_back(tmp);
        }
    );

    std::map<String_t, Sti_t> jump_table;
    std::map<String_t, Sti_t> symbol_table;

    Sti_t jump_symbols = 0;
    Sti_t max_symbol = static_cast<Sti_t>(Symbol::END_REGISTER_SYMBOLS); // Registers have their own space


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
    std::cout << "Generated jump table succesfully" << std::endl;


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
        else if (s == "ptr")
            ;
        else if (s == "mrk")
            ;
        else // Yay, it's a symbol!
        {
            if ((i >= 1 && m_instructions[i - 1] != "goto") || (i >= 2 && m_instructions[i - 2] != "if"))
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
            a(Symbol::ins);
        else if (s == "del")
            a(Symbol::del);
        else if (s == "bck")
            a(Symbol::bck);
        else if (s == "cnt")
            a(Symbol::cnt);
        else if (s == "find")
            a(Symbol::find);
        else if (s == "size")
            a(Symbol::size);
        else if (s == "capt")
            a(Symbol::capt);
        else if (s == "trim")
            a(Symbol::trim);
        else if (s == "cnc")
            a(Symbol::cnc);
        else if (s == "drf")
            a(Symbol::drf);
        else if (s == "rdf")
            a(Symbol::rdf);
        else if (s == "swap")
            a(Symbol::swap);
        else if (s == "dir")
            a(Symbol::dir);
        else if (s == "odir")
            a(Symbol::odir);
        else if (s == "isdr")
            a(Symbol::isdr);
        else if (s == "extp")
            a(Symbol::extp);
        else if (s == "updr")
            a(Symbol::updr);
        else if (s == "fln")
            a(Symbol::fln);
        else if (s == "adir")
            a(Symbol::adir);
        else if (s == "show")
            a(Symbol::show);
        else if (s == "reset")
            a(Symbol::reset);
        else if (s == "if")
            a(Symbol::if_statement);
        else if (s == "goto")
            a(Symbol::goto_statement);
        else if (s == "eq")
            a(Symbol::eq);
        else if (s == "neq")
            a(Symbol::neq);
        else if (s == "lt")
            a(Symbol::lt);
        else if (s == "st")
            a(Symbol::st);
        else if (s == "inc")
            a(Symbol::inc);
        else if (s == "dec")
            a(Symbol::dec);
        else if (s == "add")
            a(Symbol::add);
        else if (s == "sub")
            a(Symbol::sub);
        else if (s == "push")
            a(Symbol::push);
        else if (s == "pop")
            a(Symbol::pop);
        else if (s == "mov")
            a(Symbol::mov);
        else if (s == "cpy")
            a(Symbol::cpy);
        else if (s == "next")
            a(Symbol::next);
        else if (s == "prev")
            a(Symbol::prev);
        else if (s == "and")
            a(Symbol::and_statement);
        else if (s == "or")
            a(Symbol::or_statement);
        else if (s == "xor")
            a(Symbol::xor_statement);
        else if (s == "not")
            a(Symbol::not_statement);
        else if (s == "ptr")
            a(Symbol::ptr);
        else if (s == "mrk")
            a(Symbol::mrk);
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
                    (instructions.back()[0] == static_cast<Symbol_enum_t>(Symbol::goto_statement))
                    ||
                    (tmp[0] == static_cast<Symbol_enum_t>(Symbol::if_statement))
                )
            )
            {
                b(jump_table[s]);
            }
            else if (i < 2 || (i >= 2 && static_cast<Symbol_enum_t>(instructions[i - 2][0]) != static_cast<Symbol_enum_t>(Symbol::cpy)))
            {
                b(symbol_table[s]);
            }
            else
            {
                instructions.push_back(s);
            }
        }
    }
    std::cout << "Translation complete" << std::endl;

    std::fstream st("compiled.cxy", std::ios::out);
    for (auto &x : instructions)
        st << x << ' ';

    std::swap(instructions, m_instructions);


    std::string utmp;
    utmp.push_back(char (Symbol::eq));

    for (Sti_t i = 0; i < Sti_t(Symbol::END_REGISTER_SYMBOLS); ++i)
    {
        utmp[0] = (char) (static_cast<Symbol>(i));
        m_id[Sti_t(Runstate::Execute)][i] = utmp;

        std::cout << "Symbol " << i << " : " << utmp << std::endl;

        m_data[m_id[Sti_t(Runstate::Execute)][i]].emplace_back("0");
        m_data[m_id[Sti_t(Runstate::Execute)][i]] = m_data[m_id[Sti_t(Runstate::Interpret)][i]];
    }

    std::cout << "Exited function here\n";
}

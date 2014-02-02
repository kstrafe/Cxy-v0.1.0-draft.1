// Headers
#include "File.hpp"
#include <chrono>
#include <iomanip>


void File::compile()
{

//    std::cout << "Initializing variables..." << std::endl;

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
    Sti_t max_symbol = static_cast<Sti_t>(Symbol::END_REGISTER_SYMBOLS);
    // Registers have their own space, we can not use symbols in that range


    // Generate jump table
//    std::cout << "Generating jump table..." << std::endl;
    for (Sti_t i = 0; i < m_instructions.size(); ++i)
    {
        String_t &s(m_instructions[i]);
        if (s[0] == ':')
        {
            if (i >= 2 && m_instructions[i - 2] != "cpy")
            {

                //            jump_table[s.substr(1)] = i - 1; // The jump codes are removed from compiled code, only the address is stored.
//                std::cout << "2 INSTR AGO: " << m_instructions[i - 2] << "\n";
//                std::cout << "Assigning jump pos: " << i - jump_symbols << " to " << s << std::endl;
//                std::cout << "Generating jump code for: " << s << " with number: " << i << " minus " << (jump_symbols) << "\n";
                jump_table[s.substr(1)] = i - jump_symbols++; // The jump codes are removed from compiled code, only the address is stored.

            }
            else if (i < 2)
            {
//                std::cout << "Generating jump code for2: " << s << " with number: " << i << " minus " << (jump_symbols) << "\n";
//                std::cout << "Assigning jump pos2: " << i - jump_symbols << " to " << s << std::endl;
                jump_table[s.substr(1)] = i - jump_symbols++; // The jump codes are removed from compiled code, only the address is stored.
            }

        }
    }
//    std::cout << "Generated jump table succesfully" << std::endl;


    // Generate symbol table
//    std::cout << "Generating symbol table..." << std::endl;

    symbol_table["cnt"] = static_cast<Sti_t>(Symbol::cnt);
    symbol_table["eq"] = static_cast<Sti_t>(Symbol::eq);
    symbol_table["neq"] = static_cast<Sti_t>(Symbol::neq);
    symbol_table["lt"] = static_cast<Sti_t>(Symbol::lt);
    symbol_table["st"] = static_cast<Sti_t>(Symbol::st);
    symbol_table["ptr"] = static_cast<Sti_t>(Symbol::ptr);
    symbol_table["mrk"] = static_cast<Sti_t>(Symbol::mrk);
    symbol_table["size"] = static_cast<Sti_t>(Symbol::size);
    symbol_table["next"] = static_cast<Sti_t>(Symbol::next);
    symbol_table["prev"] = static_cast<Sti_t>(Symbol::prev);
    symbol_table["and"] = static_cast<Sti_t>(Symbol::and_statement);
    symbol_table["or"] = static_cast<Sti_t>(Symbol::or_statement);
    symbol_table["xor"] = static_cast<Sti_t>(Symbol::xor_statement);
    symbol_table["not"] = static_cast<Sti_t>(Symbol::not_statement);
    symbol_table["capt"] = static_cast<Sti_t>(Symbol::capt);
    symbol_table["drf"] = static_cast<Sti_t>(Symbol::drf);
    symbol_table["cntnt"] = static_cast<Sti_t>(Symbol::cntnt);
    symbol_table["odir"] = static_cast<Sti_t>(Symbol::odir);
    symbol_table["isdr"] = static_cast<Sti_t>(Symbol::isdr);
    symbol_table["extp"] = static_cast<Sti_t>(Symbol::extp);
    symbol_table["fln"] = static_cast<Sti_t>(Symbol::fln);
    symbol_table["match"] = static_cast<Sti_t>(Symbol::match);
    symbol_table["get"] = static_cast<Sti_t>(Symbol::get);
    symbol_table["set"] = static_cast<Sti_t>(Symbol::set);
    symbol_table["hght"] = static_cast<Sti_t>(Symbol::hght);

    for (Sti_t i = 0; i < m_instructions.size(); ++i)
    {
        String_t &s(m_instructions[i]);

        if (s[0] == ':')
            ;
        else if (s == "ins")
            ;
        else if (s == "del")
            ;
        else if (s == "bck")
            ;
        else if (s == "cnt")
            ;
        else if (s == "find")
            ;
        else if (s == "rfind")
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
        else if (s == "repl")
            ;
        else if (s == "match")
            ;
        else if (s == "srch")
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
        else if (s == "get")
            ;
        else if (s == "set")
            ;
        else if (s == "hght")
            ;
//        else if (s == "ptr")
//            ;
//        else if (s == "mrk")
//            ;
        else // Yay, it's a symbol!
        {
            if ((i >= 1 && m_instructions[i - 1] != "goto"))
            {
                if (i >= 2 && m_instructions[i - 2] != "if")
                {
                    if (m_instructions[i - 2] != "cpy")
                    {
                        auto x = symbol_table.find(s);
                        if (x == symbol_table.end())
                        {
                            symbol_table[s] = max_symbol++;
                        }
                    }
                }
            }
        }
    }
//    std::cout << "Finished generating symbol table succesfully" << std::endl;


    // Translate to bytecode:
//    std::cout << "Translating to Cxy bytecode..." << std::endl;
    for (Sti_t i = 0; i < m_instructions.size(); ++i)
    {
        String_t &s(m_instructions[i]);

        if (s[0] == ':')
            ;
        else if (s == "ins")
        {
            a(Symbol::ins);
            b(symbol_table[m_instructions[i + 1]]);
            i += 1;
        }
        else if (s == "del")
        {
            a(Symbol::del);
        }
        else if (s == "bck")
        {
            a(Symbol::bck);
        }
        else if (s == "cnt")
        {
            a(Symbol::cnt);
            b(symbol_table[m_instructions[i + 1]]);
            i += 1;
        }
        else if (s == "find")
        {
            a(Symbol::find);
            b(symbol_table[m_instructions[i + 1]]);
            i += 1;
        }
        else if (s == "rfind")
        {
            a(Symbol::rfind);
            b(symbol_table[m_instructions[i + 1]]);
            i += 1;
        }
        else if (s == "size")
        {
            a(Symbol::size);
            b(symbol_table[m_instructions[i + 1]]);
            i += 1;
        }
        else if (s == "capt")
            a(Symbol::capt);
        else if (s == "trim")
        {
            a(Symbol::trim);
            b(symbol_table[m_instructions[i + 1]]);
            i += 1;
        }
        else if (s == "cnc")
        {
            a(Symbol::cnc);
            b(symbol_table[m_instructions[i + 1]]);
            b(symbol_table[m_instructions[i + 2]]);
            i += 2;
        }
        else if (s == "drf")
        {
            a(Symbol::drf);
            b(symbol_table[m_instructions[i + 1]]);
            i += 1;
        }
        else if (s == "rdf")
        {
            a(Symbol::rdf);
            b(symbol_table[m_instructions[i + 1]]);
            b(symbol_table[m_instructions[i + 2]]);
            i += 2;
        }
        else if (s == "swap")
        {
            a(Symbol::swap);

            b(symbol_table[m_instructions[i + 1]]);
            b(symbol_table[m_instructions[i + 2]]);

            i += 2;
        }
        else if (s == "repl")
        {
            a(Symbol::repl);

            b(symbol_table[m_instructions[i + 1]]);
            b(symbol_table[m_instructions[i + 2]]);

            i += 2;
        }
        else if (s == "match")
        {
            a(Symbol::match);

            b(symbol_table[m_instructions[i + 1]]);

            i += 1;
        }
        else if (s == "srch")
        {
            a(Symbol::srch);
            b(symbol_table[m_instructions[i + 1]]);
            i += 1;
        }
        else if (s == "hght")
        {
            a(Symbol::hght);
            b(symbol_table[m_instructions[i + 1]]);
            i += 1;
        }
        else if (s == "dir")
        {
            a(Symbol::dir);
            b(symbol_table[m_instructions[i + 1]]);
            i += 1;
        }
        else if (s == "odir")
        {
            a(Symbol::odir);
        }
        else if (s == "isdr")
        {
            a(Symbol::isdr);
        }
        else if (s == "extp")
        {
            a(Symbol::extp);
        }
        else if (s == "updr")
        {
            a(Symbol::updr);
        }
        else if (s == "fln")
        {
            a(Symbol::fln);
        }
        else if (s == "adir")
        {
            a(Symbol::adir);
        }
        else if (s == "show")
        {
            a(Symbol::show);
            b(symbol_table[m_instructions[i + 1]]);
            i += 1;
        }
        else if (s == "reset")
        {
            a(Symbol::reset);
        }
        else if (s == "if")
        {
            a(Symbol::if_statement);
            b(symbol_table[m_instructions[i + 1]]);
            b(jump_table[m_instructions[i + 2]]);
            i += 2;
        }
        else if (s == "goto")
        {
            a(Symbol::goto_statement);
            b(jump_table[m_instructions[i + 1]]);
            i += 1;
        }
        else if (s == "eq")
        {
            a(Symbol::eq);
            b(symbol_table[m_instructions[i + 1]]);
            b(symbol_table[m_instructions[i + 2]]);
            i += 2;
        }
        else if (s == "neq")
        {
            a(Symbol::neq);
            b(symbol_table[m_instructions[i + 1]]);
            b(symbol_table[m_instructions[i + 2]]);
            i += 2;
        }
        else if (s == "lt")
        {
            a(Symbol::lt);
            b(symbol_table[m_instructions[i + 1]]);
            b(symbol_table[m_instructions[i + 2]]);
            i += 2;
        }
        else if (s == "st")
        {
            a(Symbol::st);
            b(symbol_table[m_instructions[i + 1]]);
            b(symbol_table[m_instructions[i + 2]]);
            i += 2;
        }
        else if (s == "inc")
        {
            a(Symbol::inc);
            b(symbol_table[m_instructions[i + 1]]);
            i += 1;
        }
        else if (s == "dec")
        {
            a(Symbol::dec);
            b(symbol_table[m_instructions[i + 1]]);
            i += 1;
        }
        else if (s == "add")
        {
            a(Symbol::add);
            b(symbol_table[m_instructions[i + 1]]);
            b(symbol_table[m_instructions[i + 2]]);
            i += 2;
        }
        else if (s == "sub")
        {
            a(Symbol::sub);
            b(symbol_table[m_instructions[i + 1]]);
            b(symbol_table[m_instructions[i + 2]]);
            i += 2;
        }
        else if (s == "push")
        {
            a(Symbol::push);
            b(symbol_table[m_instructions[i + 1]]);
            i += 1;
        }
        else if (s == "pop")
        {
            a(Symbol::pop);
            b(symbol_table[m_instructions[i + 1]]);
            i += 1;
        }
        else if (s == "mov")
        {
            a(Symbol::mov);
            b(symbol_table[m_instructions[i + 1]]);
            b(symbol_table[m_instructions[i + 2]]);
            i += 2;
        }
        else if (s == "cpy")
        {
            a(Symbol::cpy);
            b(symbol_table[m_instructions[i + 1]]);
            instructions.emplace_back(m_instructions[i + 2]);
            i += 2;
        }
        else if (s == "next")
        {
            a(Symbol::next);
        }
        else if (s == "prev")
        {
            a(Symbol::prev);
        }
        else if (s == "and")
        {
            a(Symbol::and_statement);
            b(symbol_table[m_instructions[i + 1]]);
            b(symbol_table[m_instructions[i + 2]]);
            i += 2;
        }
        else if (s == "or")
        {
//            std::cout << "Or statement\n";
//            std::cout << (int) Symbol::or_statement << std::endl;
            a(Symbol::or_statement);
            b(symbol_table[m_instructions[i + 1]]);
            b(symbol_table[m_instructions[i + 2]]);
            i += 2;
        }
        else if (s == "xor")
        {
            a(Symbol::xor_statement);
            b(symbol_table[m_instructions[i + 1]]);
            b(symbol_table[m_instructions[i + 2]]);
            i += 2;
        }
        else if (s == "not")
        {
            a(Symbol::not_statement);
            b(symbol_table[m_instructions[i + 1]]);
            i += 1;
        }
        else if (s == "get")
        {
            a(Symbol::get);
            b(symbol_table[m_instructions[i + 1]]);
            b(symbol_table[m_instructions[i + 2]]);
            i += 2;
        }
        else if (s == "set")
        {
            a(Symbol::set);
            b(symbol_table[m_instructions[i + 1]]);
            b(symbol_table[m_instructions[i + 2]]);
            i += 2;
        }
        else
        {
//            throw std::invalid_argument("Instruction not recognized " + s);
            std::cout << "Instruction not recognised: " << s << "\n";
        }
    }
//    std::cout << "Translation complete" << std::endl;

//    std::fstream st("compiled.cxy", std::ios::out);
//    for (auto &x : instructions)
//        st << x << ' ';


    // Fill out escape characters
    for (auto &x : instructions)
    {
        for (Sti_t i = 0; i < x.size(); ++i)
        {
            if (x[i] == '\\')
            {
                switch (x[i + 1])
                {
                    case '\'':
                        x[i + 1] = '\'';
                        break;
                    case '\"':
                        x[i + 1] = '\"';
                        break;
                    case '?':
                        x[i + 1] = '\?';
                        break;
                    case '\\':
                        x[i + 1] = '\\';
                        break;
                    case '0':
                        x[i + 1] = '\0';
                        break;
                    case 'a':
                        x[i + 1] = '\a';
                        break;
                    case 'b':
                        x[i + 1] = '\b';
                        break;
                    case 'f':
                        x[i + 1] = '\f';
                        break;
                    case 'n':
                        x[i + 1] = '\n';
                        break;
                    case 'r':
                        x[i + 1] = '\r';
                        break;
                    case 't':
                        x[i + 1] = '\t';
                        break;
                    case 'v':
                        x[i + 1] = '\v';
                        break;
                    default:
                        break;
                }
                x.erase(i, 1);
            }
        }
    }

    // Swap and go!
    std::swap(instructions, m_instructions);

//    std::cout << "Symbol Mapping:\n\n";
//    for (auto i = symbol_table.begin(); i != symbol_table.end(); ++i)
//    {
//        std::cout << std::setw(10) << i->first
//             << " -> " << i->second << "\n";
//    }
//    std::cout << "\nEnd of Symbol Mapping\n\n";


    // For each previously defined data, translate to our new state
//    for (auto i = m_data.begin(); i != m_data.end(); ++i)
//    {
//        auto pos = symbol_table.find(i->first);
//        if (pos == symbol_table.end())
//        {
//            symbol_table[i->first] = max_symbol++;
//        }
//    }

    // Translate old standard register data into the new ones'
    // NO LONGER NECESSARY
//    for (auto i = m_data.begin(); i != m_data.end(); ++i)
//    {
//        if (symbol_table[i->first] <= std::numeric_limits<char>::max())
//        {
//            std::string tmp(1, (char) symbol_table[i->first]);
//            m_data[tmp] = i->second;
//        }
//    }


//    for (Sti_t i = 0; i < Sti_t(Symbol::END_REGISTER_SYMBOLS); ++i)
//    {
//
//        m_data[m_id[Sti_t(Runstate::Execute)][i]]
//            = m_data[m_id[Sti_t(Runstate::Interpret)][i]];
//
//        if (Symbol::cntnt == static_cast<Symbol>(i))
//        {
//            std::cout << "Compiler: Found cntnt symbol: " << static_cast<char>(i) << " with content: " << (m_data[m_id[Sti_t(Runstate::Interpret)][i]]).back() << "\n";
//            std::cout << "Copied: " << getString(Symbol::cntnt) << "\n";
//        }
//    }
}

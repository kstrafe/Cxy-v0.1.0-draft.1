// Headers
#include "File.hpp"


auto File::parseStatements(Sti_t position) -> Sti_t
{
    Sti_t nesting = 0;
    std::vector<std::pair<Sti_t, Sti_t>> nest_range;
    if (getString("cntnt")[position + 1] == '\n'/* || getString("cntnt")[position + 1] == '\r'*/)
    {
        ++position;
        while (true)
        {
            String_t statement(std::move(tokenize(getString("cntnt"), position)));
//            std::cout << "TOKEN: " << statement << "\n";
            if (statement.size() == 0)
            {
                return position;
            }
            else if (statement == "#cxy start")
            {
                ++nesting;
                nest_range.emplace_back(std::make_pair(position, 0));
            }
            else if (statement == "#cxy starb")
            {
                {
                    Sti_t nextend = std::string(m_data["cntnt"].back()).find("#cxy stob", position);
                    if (nextend == std::string::npos)
                        nextend = std::string(m_data["cntnt"].back()).size();
//                        std::cout << "POS AT: " << position << "\n";
//                        std::cout << "ENDING AT: " << nextend << "\n";

                    std::string tmp = std::string(m_data["cntnt"].back()).substr
                    (position, nextend - position);
                    getString("cntnt").erase(position, nextend - position);
//                        std::cout << "After erasure:\n" << getString("cntnt") << "\n";

                    m_data["cntnt"].emplace_back(tmp);
//                        std::cout << "Nested data to be processed:\n" << tmp << "\nEND NESTED DATA TO BE PROCESSED\n";
                    execute();
                    m_instructions.clear();
//                        std::cout << "AFTER NEST RUN: " << std::string(m_data["cntnt"].back()) << "\n";
                    auto a = getString("cntnt");
                    std::string &r = m_data["cntnt"][0];

                    r.insert(position, a);
                    m_data["cntnt"].pop_back();

                }
            }
//            else if (statement == "#cxy starb")
//            {
//                // We know that this is impossible to nest any further:
//                // We must run this.
//                parseBinaryStatements(position + sizeof("#cxy starb\n") - 1);
//                execute();
//            }
            else if (statement == "#cxy stop")
            {
                if (nesting > 0)
                {
//                    std::cout << "NEST DETECTED\n";
                    --nesting;
                    position += sizeof("#cxy stop") / sizeof(char);
                    nest_range[nesting].second = position;

//                    if (nest_range.size() == (nesting + 3))
                    {
                        Sti_t nextend = std::string(m_data["cntnt"].back()).find("#cxy stop", position);
                        if (nextend == std::string::npos)
                            nextend = std::string(m_data["cntnt"].back()).size();
//                        std::cout << "POS AT: " << position << "\n";
//                        std::cout << "ENDING AT: " << nextend << "\n";

                        std::string tmp = std::string(m_data["cntnt"].back()).substr
                        (position, nextend - position);
                        getString("cntnt").erase(position, nextend - position);
//                        std::cout << "After erasure:\n" << getString("cntnt") << "\n";

                        m_data["cntnt"].emplace_back(tmp);
//                        std::cout << "Nested data to be processed:\n" << tmp << "\nEND NESTED DATA TO BE PROCESSED\n";
                        interpret();
                        m_instructions.clear();
//                        std::cout << "AFTER NEST RUN: " << std::string(m_data["cntnt"].back()) << "\n";
                        auto a = getString("cntnt");
                        std::string &r = m_data["cntnt"][0];

                        r.insert(position, a);
                        m_data["cntnt"].pop_back();

                    }

//                    std::cout << "ns size: " << nest_range.size() << " ns index: " << nesting << "\n";
//                    std::cout << "ns: " << nest_range[nesting].first << " ns: " << nest_range[nesting].second << "\n\n\n";
                }
                else
                {
                    return position;
                }
            }
            else
            {
                m_instructions.emplace_back(std::move(statement));
            }
        }
    }
    else
    {
        throw std::runtime_error("\"#cxy start\" must be superseded by a new line.");
    }
    return position;
}

// Headers
#include "File.hpp"


auto File::getNextArgument(const String_t &str, Sti_t &position) -> String_t
{
    static constexpr const Sti_t FIRST = 1, LAST = 1;

    String_t nruter;
    Sti_t eos; // end of statement
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

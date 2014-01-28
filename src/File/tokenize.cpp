// Headers
#include "File.hpp"


// Tokenize according to laws:
/*
    Space-separation, alphanumeric, ""-encapsulated strings.
*/
auto File::tokenize(const String_t &str, Sti_t &position) -> String_t
{
    static constexpr const Sti_t FIRST = 1, LAST = 1, DELIMCHAR = 1 * sizeof(char);

    String_t nruter;
    Sti_t eos; // end of statement
    while (position < str.size())
    {
        // Skip to the end of the line if there is a // token
        if (str[position] == '/' && str[position + 1] == '/') // Comments
        {
            for (; position < str.size(); ++position)
            {
                if (str[position] == '\n')
                    break;
            }
        }
        // Parse as token if it is alpha-numeric (A-Z, a-z, 0-9)
        else if (std::isalnum(str[position])) // Raw alpha-numeric code
        {
            for (eos = position; eos < str.size() && (std::isalnum(str[eos])); ++eos);
            nruter = str.substr(position, eos - position);
            position = eos + 1;
            return nruter;
        }
        else if (str[position] == '\"') // Internal string, can contain EVERYTHING, until next "
        {
            for (eos = position + 1; eos < str.size() && str[eos] != '\"'; ++eos)
            {
                if (str[eos] == '\\')
                {
                    ++eos;
                }
            }
            nruter = str.substr(position + FIRST /* First is a " */, eos - position - LAST /* Last is a " */);
            position = eos + 1;
            return nruter;
        }
        else if (str[position] == m_parser_sign)
        {
            if (str.substr(position, sizeof("#cxy stop") / sizeof(char) - DELIMCHAR) == "#cxy stop")
            {
                return "#cxy stop";
            }
            else if (str.substr(position, sizeof("#cxy start") / sizeof(char) - DELIMCHAR) == "#cxy start")
            {
                position += sizeof("#cxy start") / sizeof(char);
                return "#cxy start";
            }
            else if (str.substr(position, sizeof("#cxy stob") / sizeof(char) - DELIMCHAR) == "#cxy stob")
            {
                position += sizeof("#cxy stob") / sizeof(char);
                return "#cxy stob";
            }
            else if (str.substr(position, sizeof("#cxy starb") / sizeof(char) - DELIMCHAR) == "#cxy starb")
            {
                position += sizeof("#cxy starb") / sizeof(char);
                return "#cxy starb";
            }
            ++position;
            return "#";
        }
        else if (str[position] == ':') // Jumping location
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

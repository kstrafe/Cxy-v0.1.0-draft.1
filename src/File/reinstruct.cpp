#include "File.hpp"


void File::reinstruct(const std::string &instructions)
{
    m_instructions.clear();
    for (Sti_t position = 0; position < instructions.size();)
    {
        std::string tmp = tokenize(instructions, position);
        if (tmp.size() > 0)
            m_instructions.emplace_back(tmp);
        else
            break;
    }
}

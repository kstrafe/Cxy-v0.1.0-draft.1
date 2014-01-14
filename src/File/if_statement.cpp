// Headers
#include  "File.hpp"


void File::if_statement(Sti_t &i)
{
    if (getNumber(m_instructions[++i]))
    {
        return;
    }
    else // skip the entire if
    {
        Sti_t nests = 0; // Nests: if inside if; we need to keep track of openers vs closers
        ++i;
        for (; i < m_instructions.size(); ++i)
        {
            if (m_instructions[i] != "stop")
            {
                if (m_instructions[i] == "if")
                {
                    ++nests;
                }
            }
            else
            {
                if (nests == 0) // This is the stop that corresponds with our initial if
                {
                    break;
                }
                else
                {
                    --nests;
                }
            }
        }
    }
}

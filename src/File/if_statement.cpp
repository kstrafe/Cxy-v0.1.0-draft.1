// Headers
#include  "File.hpp"


void File::if_statement(Sti_t &i)
{
    if ( getNumber(m_instructions[++i]) != 0 ) // If the number goes to false
    {
        ++i; // Hop over the next location
        return;
    }
    else // skip the entire if
    {
        goto_statement(i);
//        Sti_t nests = 0; // Nests: if inside if; we need to keep track of openers vs closers
//        ++i;
//        for (; i < m_instructions.size(); ++i)
//        {
//            if (m_instructions[i] != "stop")
//            {
//                if (m_instructions[i] == "if")
//                {
//                    ++nests;
//                }
//            }
//            else
//            {
//                if (nests == 0) // This is the stop that corresponds with our initial if
//                {
//                    break;
//                }
//                else
//                {
//                    --nests;
//                }
//            }
//        }
    }
}


void File::if_statement_c(Sti_t &i)
{
    if ( getNumber(m_instructions[++i]) != 0 ) // If the number goes to false
    {
        ++i; // Hop over the next location
        return;
    }
    else // skip the entire if
    {
        goto_statement_c(i);
//        Sti_t nests = 0; // Nests: if inside if; we need to keep track of openers vs closers
//        ++i;
//        for (; i < m_instructions.size(); ++i)
//        {
//            if (m_instructions[i] != "stop")
//            {
//                if (m_instructions[i] == "if")
//                {
//                    ++nests;
//                }
//            }
//            else
//            {
//                if (nests == 0) // This is the stop that corresponds with our initial if
//                {
//                    break;
//                }
//                else
//                {
//                    --nests;
//                }
//            }
//        }
    }
}

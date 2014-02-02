// Headers
#include "File.hpp"


/*
    Stores the "height" of a register in hght
*/
void File::hght(Sti_t &i)
{
    getRegister(Symbol::hght) = m_data[m_instructions[i + 1]].size();
    i += 1;
}

// Headers
#include "File.hpp"


/*
    Returns an item from a stack and stores it into "get"
*/
void File::get(Sti_t &i)
{
    getRegister(Symbol::get) = m_data[m_instructions[i + 1]][getNumber(m_instructions[i + 2])];

    i += 2;
}

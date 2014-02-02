// Headers
#include "File.hpp"


/*
    Copies from set into argument 1, with offset argument 2.
*/
void File::set(Sti_t &i)
{
    m_data[m_instructions[i + 1]][getNumber(m_instructions[i + 2])] = getRegister(Symbol::set);
    i += 2;
}

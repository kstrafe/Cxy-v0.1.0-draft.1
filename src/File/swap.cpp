// Headers
#include "File.hpp"


void File::swap(Sti_t &i)
{
    std::swap(getRegister( m_instructions[i + 1] ), getRegister( m_instructions[i + 2]));
    i += 2;
}

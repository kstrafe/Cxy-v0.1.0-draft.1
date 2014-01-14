// Headers
#include  "File.hpp"


void File::cpy(Sti_t &i)
{
    getRegister(m_instructions[i + 1]) = m_instructions[i + 2];
    i += 2;
}

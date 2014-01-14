// Headers
#include  "File.hpp"


void File::dec(Sti_t &i)
{
    Sti_t num = getNumber(m_instructions[++i]);
    getRegister(m_instructions[i]) = num - 1;
}

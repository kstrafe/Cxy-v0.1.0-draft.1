// Headers
#include  "File.hpp"


void File::add(Sti_t &i)
{
    Sti_t num = getNumber(m_instructions[++i]);
    getRegister(m_instructions[i]) = num + getNumber(m_instructions[i + 1]);
    ++i;
}

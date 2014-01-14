// Headers
#include  "File.hpp"


void File::sub(Sti_t &i)
{
    Sti_t num = getNumber(m_instructions[++i]);
    Sti_t num2 = getNumber(m_instructions[i + 1]);
    getRegister(m_instructions[i]) = num - (num2 > num ? num : num2);
    ++i;
}

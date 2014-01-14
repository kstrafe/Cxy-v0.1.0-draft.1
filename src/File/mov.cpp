// Headers
#include  "File.hpp"


void File::mov(Sti_t &i)
{
    getRegister(m_instructions[i + 1]) = getString(m_instructions[i + 2]);
    i += 2;
}

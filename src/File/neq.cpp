// Headers
#include  "File.hpp"


void File::neq(Sti_t &i)
{
    getRegister(Symbol::neq) = (getString(m_instructions[i + 1]) != getString(m_instructions[i + 2]) ? 1 : 0);
    i += 2;
}

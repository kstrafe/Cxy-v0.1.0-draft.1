// Headers
#include  "File.hpp"


void File::lt(Sti_t &i)
{
    Sti_t a = getNumber(m_instructions[i + 1]),
        b = getNumber(m_instructions[i + 2]);
    getString("lt")[0] = (a > b ? '1' : '0');
    i += 2;
}

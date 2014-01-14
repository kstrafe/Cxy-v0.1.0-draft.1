// Headers
#include  "File.hpp"


void File::st(Sti_t &i)
{
    Sti_t
        a = getNumber(m_instructions[i + 1]),
        b = getNumber(m_instructions[i + 2]);
    getRegister("st") = (a < b ? 1 : 0);
    i += 2;
}

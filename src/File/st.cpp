// Headers
#include  "File.hpp"


void File::st(Sti_t &i)
{
    String_t &a = getString(m_instructions[i + 1]),
                &b = getString(m_instructions[i + 2]);
    getString("st")[0] = (a < b ? '1' : '0');
    i += 2;
}

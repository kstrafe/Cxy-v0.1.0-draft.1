// Headers
#include  "File.hpp"


void File::eq(Sti_t &i)
{
    getString("eq")[0] = (getString(m_instructions[i + 1]) == getString(m_instructions[i + 2]) ? '1' : '0');
    i += 2;
}

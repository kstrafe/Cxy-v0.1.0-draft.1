// Headers
#include  "File.hpp"


void File::dec(Sti_t &i)
{
    Sti_t num = getNumber(m_instructions[++i]);
    getString(m_instructions[i]) = std::to_string(num - 1);
}

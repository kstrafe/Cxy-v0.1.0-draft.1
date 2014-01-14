// Headers
#include  "File.hpp"


void File::add(Sti_t &i)
{
    Sti_t num = getNumber(m_instructions[++i]);
    getString(m_instructions[i]) = std::to_string(num + getNumber(m_instructions[i + 1]));
    ++i;
}

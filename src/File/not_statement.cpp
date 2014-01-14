// Headers
#include  "File.hpp"


void File::not_statement(Sti_t &i)
{
    getString("not") = std::to_string(!getNumber(m_instructions[i + 1]));
    ++i;
}

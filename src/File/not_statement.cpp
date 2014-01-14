// Headers
#include  "File.hpp"


void File::not_statement(Sti_t &i)
{
    getRegister("not") = !getNumber(m_instructions[i + 1]);
    ++i;
}

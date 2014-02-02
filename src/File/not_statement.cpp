// Headers
#include  "File.hpp"


void File::not_statement(Sti_t &i)
{
    getRegister(Symbol::not_statement) = !getNumber(m_instructions[i + 1]);
    ++i;
}

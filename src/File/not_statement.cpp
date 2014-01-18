// Headers
#include  "File.hpp"


void File::not_statement(Sti_t &i)
{
    getRegister("not") = !getNumber(m_instructions[i + 1]);
    ++i;
}


void File::not_statement_c(Sti_t &i)
{
    getRegister(Instruction::not_statement) = !getNumber(m_instructions[i + 1]);
    ++i;
}

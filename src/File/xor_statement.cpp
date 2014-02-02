// Headers
#include  "File.hpp"


void File::xor_statement(Sti_t &i)
{
    getRegister(Symbol::xor_statement) =
    (
        getNumber(m_instructions[i + 1])
        != getNumber(m_instructions[i + 2])
        ?
            1
            :
            0
    );

    i += 2;
}

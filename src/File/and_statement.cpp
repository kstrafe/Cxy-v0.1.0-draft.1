// Headers
#include  "File.hpp"


void File::and_statement(Sti_t &i)
{
    getRegister(reg2str(Symbol::and_statement)) =
    (
        getNumber(m_instructions[i + 1])
        && getNumber(m_instructions[i + 2])
        ?
            1
            :
            0
    );

    i += 2;
}

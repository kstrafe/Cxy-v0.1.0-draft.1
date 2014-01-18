// Headers
#include  "File.hpp"


void File::xor_statement(Sti_t &i)
{
    m_data[reg2str(Symbol::xor_statement)].back() =
    (
        getNumber(m_instructions[i + 1])
        != getNumber(m_instructions[i + 2])
        ?
            "true"
            :
            "false"
    );

    i += 2;
}

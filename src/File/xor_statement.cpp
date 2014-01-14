// Headers
#include  "File.hpp"


void File::xor_statement(Sti_t &i)
{
    m_data["xor"].back() =
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

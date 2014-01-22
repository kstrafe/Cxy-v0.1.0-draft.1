// Headers
#include  "File.hpp"


void File::or_statement(Sti_t &i)
{
    m_data[reg2str(Symbol::or_statement)].back() =
    (
        getNumber(m_instructions.at(i + 1))
        || getNumber(m_instructions.at(i + 2))
         ?
            "true"
            :
            "false"
    );

    i += 2;
}

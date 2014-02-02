// Headers
#include  "File.hpp"


void File::or_statement(Sti_t &i)
{
    getRegister(Symbol::or_statement) =
    (
        getNumber(m_instructions.at(i + 1))
        || getNumber(m_instructions.at(i + 2))
         ?
            1
            :
            0
    );

    i += 2;
}

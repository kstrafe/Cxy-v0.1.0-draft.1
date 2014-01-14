// Headers
#include  "File.hpp"


void File::and_statement(Sti_t &i)
{
    m_data["and"].back() =
    (
        getNumber(m_statements[i + 1])
        && getNumber(m_statements[i + 2])
        ?
            "true"
            :
            "false"
    );

    i += 2;
}

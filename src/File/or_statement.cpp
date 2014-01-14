// Headers
#include  "File.hpp"


void File::or_statement(sti &i)
{
    m_data["or"].back() =
    (
        getNumber(m_statements[i + 1])
        || getNumber(m_statements[i + 2])
         ?
            "true"
            :
            "false"
    );

    i += 2;
}

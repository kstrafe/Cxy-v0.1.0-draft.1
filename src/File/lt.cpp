// Headers
#include  "File.hpp"


void File::lt(Sti_t &i)
{
    Sti_t a = getNumber(m_statements[i + 1]),
        b = getNumber(m_statements[i + 2]);
    getData("lt")[0] = (a > b ? '1' : '0');
    i += 2;
}

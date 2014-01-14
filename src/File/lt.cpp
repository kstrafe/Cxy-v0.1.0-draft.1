// Headers
#include  "File.hpp"


void File::lt(sti &i)
{
    sti a = getNumber(m_statements[i + 1]),
        b = getNumber(m_statements[i + 2]);
    getData("lt")[0] = (a > b ? '1' : '0');
    i += 2;
}

// Headers
#include  "File.hpp"


void File::eq(Sti_t &i)
{
    getData("eq")[0] = (getData(m_statements[i + 1]) == getData(m_statements[i + 2]) ? '1' : '0');
    i += 2;
}
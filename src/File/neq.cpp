// Headers
#include  "File.hpp"


void File::neq(Sti_t &i)
{
    getData("neq")[0] = (getData(m_statements[i + 1]) != getData(m_statements[i + 2]) ? '1' : '0');
    i += 2;
}

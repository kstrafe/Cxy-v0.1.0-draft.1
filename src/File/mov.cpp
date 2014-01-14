// Headers
#include  "File.hpp"


void File::mov(Sti_t &i)
{
    getData(m_statements[i + 1]) = getData(m_statements[i + 2]);
    i += 2;
}

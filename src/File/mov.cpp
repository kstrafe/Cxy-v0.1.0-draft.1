// Headers
#include  "File.hpp"


void File::mov(sti &i)
{
    getData(m_statements[i + 1]) = getData(m_statements[i + 2]);
    i += 2;
}

// Headers
#include  "File.hpp"


void File::cpy(sti &i)
{
    getData(m_statements[i + 1]) = m_statements[i + 2];
    i += 2;
}

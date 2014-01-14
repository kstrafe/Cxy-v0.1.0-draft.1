// Headers
#include  "File.hpp"


void File::dec(sti &i)
{
    sti num = getNumber(m_statements[++i]);
    getData(m_statements[i]) = std::to_string(num - 1);
}

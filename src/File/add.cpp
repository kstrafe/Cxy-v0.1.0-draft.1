// Headers
#include  "File.hpp"


void File::add(sti &i)
{
    sti num = getNumber(m_statements[++i]);
    getData(m_statements[i]) = std::to_string(num + getNumber(m_statements[i + 1]));
    ++i;
}

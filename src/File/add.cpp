// Headers
#include  "File.hpp"


void File::add(Sti_t &i)
{
    Sti_t num = getNumber(m_statements[++i]);
    getData(m_statements[i]) = std::to_string(num + getNumber(m_statements[i + 1]));
    ++i;
}

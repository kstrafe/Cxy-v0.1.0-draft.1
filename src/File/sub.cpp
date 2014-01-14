// Headers
#include  "File.hpp"


void File::sub(Sti_t &i)
{
    Sti_t num = getNumber(m_statements[++i]);
    Sti_t num2 = getNumber(m_statements[i + 1]);
    getData(m_statements[i]) = std::to_string(num - (num2 > num ? num : num2));
    ++i;
}

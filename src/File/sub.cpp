// Headers
#include  "File.hpp"


void File::sub(sti &i)
{
    sti num = getNumber(m_statements[++i]);
    sti num2 = getNumber(m_statements[i + 1]);
    getData(m_statements[i]) = std::to_string(num - (num2 > num ? num : num2));
    ++i;
}

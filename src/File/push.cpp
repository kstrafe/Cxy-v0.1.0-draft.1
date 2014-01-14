// Headers
#include  "File.hpp"


void File::push(sti &i)
{
    if (m_data[m_statements[i + 1]].size() > 0)
        m_data[m_statements[i + 1]].emplace_back(m_data[m_statements[i + 1]].back());
    else
        m_data[m_statements[i + 1]].emplace_back("");
    ++i;
}

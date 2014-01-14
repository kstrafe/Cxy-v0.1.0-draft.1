// Headers
#include  "File.hpp"


void File::pop(Sti_t &i)
{
    m_data[m_statements[++i]].pop_back();
    if (m_data[m_statements[i]].size() == 0)
        m_data.erase(m_statements[i]);
}

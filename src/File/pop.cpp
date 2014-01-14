// Headers
#include  "File.hpp"


void File::pop(Sti_t &i)
{
    m_data[m_instructions[++i]].pop_back();
    if (m_data[m_instructions[i]].size() == 0)
        m_data.erase(m_instructions[i]);
}

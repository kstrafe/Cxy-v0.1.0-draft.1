// Headers
#include  "File.hpp"


void File::goto_statement(sti &i)
{
    std::string &jumpto(m_statements[++i]);
    for (sti p = 0; p < m_statements.size(); ++p)
    {
        if (m_statements[p] == ":" + jumpto && m_statements[p - 1] != "goto")
        {
            i = p;
            return;
        }
    }
}

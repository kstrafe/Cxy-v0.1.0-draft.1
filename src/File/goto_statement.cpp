// Headers
#include  "File.hpp"


void File::goto_statement(Sti_t &i)
{
    String_t &jumpto(m_statements[++i]);
    for (Sti_t p = 0; p < m_statements.size(); ++p)
    {
        if (m_statements[p] == ":" + jumpto && m_statements[p - 1] != "goto")
        {
            i = p;
            return;
        }
    }
}

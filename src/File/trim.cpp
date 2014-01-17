// Headers
#include "File.hpp"


void File::trim(Sti_t &i)
{
    String_t &r( getString(m_instructions[++i]) );
    r.erase(0, r.find_first_not_of(' '));
    for (Sti_t i = r.size() - 1; i > 0; --i)
    {
        if (r[i] == ' ')
        {
            r.pop_back();
        }
    }
    if (r.size() == 1 && r[0] == ' ')
    {
        r.pop_back();
    }
}

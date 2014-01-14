// Headers
#include "File.hpp"


void File::find(Sti_t &i)
{
    Sti_t ptr = getNumber("ptr"),
    mrk = getNumber("mrk");

    String_t &tosrch(getString(m_instructions[++i]));
    Sti_t occurrence = 0, last = ptr - (ptr > 0 ? 1 : 0);

    if (ptr == mrk) // Unrestricted area (from pointer to file end)
    {
        if ((last = getString("cntnt").find(tosrch, (ptr > 0 ? ++last : last))) != getString("cntnt").npos)
            ptr = last;
        getString("mrk") = std::to_string(last + tosrch.size() - (ptr > 0 ? 0 : 1));
        getString("ptr") = std::to_string(ptr);
    }
    else // Restricted area (from pointer till marker)
    {
        if ((last = getString("cntnt").find(tosrch, (ptr > 0 ? ++last : last))) != getString("cntnt").npos)
        {
            if (last + tosrch.size() < mrk)
            {
                ptr = last;
                getString("mrk") = std::to_string(last + tosrch.size());
                getString("ptr") = std::to_string(ptr);
            }
        }
    }
}

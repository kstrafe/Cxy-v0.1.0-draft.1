// Headers
#include "File.hpp"


void File::cnt(Sti_t &i)
{
    const
        Sti_t ptr = getNumber("ptr"),
        mrk = getNumber("mrk");

    String_t &tosrch(getString(m_instructions[++i]));
    Sti_t occurrence = 0, last = ptr - (ptr > 0 ? 1 : 0);

    if (ptr == mrk) // Unrestricted area (from pointer to file end)
    {
        while ((last = getString("cntnt").find(tosrch, (ptr > 0 ? ++last : last))) != getString("cntnt").npos)
            ++occurrence;
    }
    else // Restricted area (from pointer till marker)
    {
        while (((last = getString("cntnt").find(tosrch, (ptr > 0 ? ++last : last))) != getString("cntnt").npos) && ((last + tosrch.size() - 1) < mrk))
            ++occurrence;
    }
    getString("cnt") = std::to_string(occurrence);
}

// Headers
#include "File.hpp"


void File::cnt(Sti_t &i)
{
    const Sti_t
        ptr = getNumber(reg2str(Symbol::ptr)),
        mrk = getNumber(reg2str(Symbol::mrk));

    String_t &tosrch(getString(m_instructions[++i]));
    Sti_t occurrence = 0, last = ptr - (ptr > 0 ? 1 : 0);

    if (ptr == mrk) // Unrestricted area (from pointer to file end)
    {
        if
        (
            (last = getString(reg2str(Symbol::cntnt)).find(tosrch, (ptr > 0 ? ++last : last))) != getString(reg2str(Symbol::cntnt)).npos
        )
        {
            ++occurrence;
            while ((last = getString(reg2str(Symbol::cntnt)).find(tosrch, (++last))) != getString(reg2str(Symbol::cntnt)).npos)
            {
                ++occurrence;
            }
        }
    }
    else // Restricted area (from pointer till marker)
    {
        if
        (
            ((last = getString(reg2str(Symbol::cntnt)).find(tosrch, (ptr > 0 ? ++last : last))) != getString(reg2str(Symbol::cntnt)).npos)
            && ((last + tosrch.size() - 1) < mrk)
        )
        {
            ++occurrence;
            while
            (
                ((last = getString(reg2str(Symbol::cntnt)).find(tosrch, (++last))) != getString(reg2str(Symbol::cntnt)).npos)
                && ((last + tosrch.size() - 1) < mrk)
            )
            {
                ++occurrence;
            }
        }
    }
    getRegister(reg2str(Symbol::cnt)) = occurrence;
}

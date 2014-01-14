// Headers
#include "File.hpp"


void File::cnt(sti &i)
{
    const
        sti ptr = getNumber("ptr"),
        mrk = getNumber("mrk");

    std::string &tosrch(getData(m_statements[++i]));
    sti occurrence = 0, last = ptr - (ptr > 0 ? 1 : 0);

    if (ptr == mrk) // Unrestricted area (from pointer to file end)
    {
        while ((last = getData("cntnt").find(tosrch, (ptr > 0 ? ++last : last))) != getData("cntnt").npos)
            ++occurrence;
    }
    else // Restricted area (from pointer till marker)
    {
        while (((last = getData("cntnt").find(tosrch, (ptr > 0 ? ++last : last))) != getData("cntnt").npos) && ((last + tosrch.size() - 1) < mrk))
            ++occurrence;
    }
    getData("cnt") = std::to_string(occurrence);
}

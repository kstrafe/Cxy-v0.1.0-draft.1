// Headers
#include "File.hpp"


void File::find(Sti_t &i)
{
    Sti_t ptr = getNumber("ptr"),
    mrk = getNumber("mrk");

    String_t &tosrch(getData(m_statements[++i]));
    Sti_t occurrence = 0, last = ptr - (ptr > 0 ? 1 : 0);

    if (ptr == mrk) // Unrestricted area (from pointer to file end)
    {
        if ((last = getData("cntnt").find(tosrch, (ptr > 0 ? ++last : last))) != getData("cntnt").npos)
            ptr = last;
        getData("mrk") = std::to_string(last + tosrch.size() - (ptr > 0 ? 0 : 1));
        getData("ptr") = std::to_string(ptr);
    }
    else // Restricted area (from pointer till marker)
    {
        if ((last = getData("cntnt").find(tosrch, (ptr > 0 ? ++last : last))) != getData("cntnt").npos)
        {
            if (last + tosrch.size() < mrk)
            {
                ptr = last;
                getData("mrk") = std::to_string(last + tosrch.size());
                getData("ptr") = std::to_string(ptr);
            }
        }
    }
}

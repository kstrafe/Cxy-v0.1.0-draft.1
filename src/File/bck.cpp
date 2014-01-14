// Headers
#include "File.hpp"


void File::bck(Sti_t &i)
{
    const
        Sti_t ptr = getNumber("ptr"),
        mrk = getNumber("mrk");

    if (ptr == mrk)
    {
        if (ptr > 0)
        {
            getData("cntnt").erase(ptr - 1, 1);
            getData("ptr") = std::to_string(ptr - 1);
        }
        else
        {
            // Backspace must be ignored
        }
    }
    else
    {
        getData("cntnt").erase(ptr, mrk - ptr);
    }
    getData("mrk") = getData("ptr");
}

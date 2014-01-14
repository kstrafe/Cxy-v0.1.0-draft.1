// Headers
#include "File.hpp"


void File::bck(Sti_t &i)
{
    const Sti_t
        ptr = getNumber("ptr"),
        mrk = getNumber("mrk");

    if (ptr == mrk)
    {
        if (ptr > 0)
        {
            getString("cntnt").erase(ptr - 1, 1);
            getRegister("ptr") = ptr - 1;
        }
        else
        {
            // Backspace must be ignored
        }
    }
    else
    {
        getString("cntnt").erase(ptr, mrk - ptr);
    }
    getRegister("mrk") = getRegister("ptr");
}

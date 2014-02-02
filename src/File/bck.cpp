// Headers
#include "File.hpp"


void File::bck(Sti_t &i)
{
    const Sti_t
        ptr = getNumber(Symbol::ptr),
        mrk = getNumber(Symbol::mrk);

    if (ptr == mrk)
    {
        if (ptr > 0)
        {
            getString(Symbol::cntnt).erase(ptr - 1, 1);
            getRegister(Symbol::ptr) = ptr - 1;
        }
        else
        {
            // Backspace must be ignored
        }
    }
    else
    {
        getString(Symbol::cntnt).erase(ptr, mrk - ptr);
    }
    getRegister(Symbol::mrk) = getRegister(Symbol::ptr);
}

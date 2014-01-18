// Headers
#include "File.hpp"


void File::bck(Sti_t &i)
{
    const Sti_t
        ptr = getNumber(reg2str(Symbol::ptr)),
        mrk = getNumber(reg2str(Symbol::mrk));

    if (ptr == mrk)
    {
        if (ptr > 0)
        {
            getString(reg2str(Symbol::cntnt)).erase(ptr - 1, 1);
            getRegister(reg2str(Symbol::ptr)) = ptr - 1;
        }
        else
        {
            // Backspace must be ignored
        }
    }
    else
    {
        getString(reg2str(Symbol::cntnt)).erase(ptr, mrk - ptr);
    }
    getRegister(reg2str(Symbol::mrk)) = getRegister(reg2str(Symbol::ptr));
}

// Headers
#include "File.hpp"


void File::del(Sti_t &i)
{
    Sti_t
        ptr = getNumber(reg2str(Symbol::ptr)),
        mrk = getNumber(reg2str(Symbol::mrk));

//    std::cout << "Ptr: " << ptr << " mrk: " << mrk << std::endl;

    if (ptr == mrk)
        ++mrk;
    getString(reg2str(Symbol::cntnt)).erase(ptr, mrk - ptr);
    getRegister(reg2str(Symbol::mrk)) = getRegister(reg2str(Symbol::ptr));
}

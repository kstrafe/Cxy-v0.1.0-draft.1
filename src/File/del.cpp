// Headers
#include "File.hpp"


void File::del(Sti_t &i)
{
    Sti_t
        ptr = getNumber(Symbol::ptr),
        mrk = getNumber(Symbol::mrk);

//    std::cout << "Ptr: " << ptr << " mrk: " << mrk << std::endl;

    if (ptr == mrk)
        ++mrk;
    getString(Symbol::cntnt).erase(ptr, mrk - ptr);
    getRegister(Symbol::mrk) = getRegister(Symbol::ptr);
}

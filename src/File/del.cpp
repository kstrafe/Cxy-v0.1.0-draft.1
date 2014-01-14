// Headers
#include "File.hpp"


void File::del(Sti_t &i)
{
    Sti_t
        ptr = getNumber("ptr"),
        mrk = getNumber("mrk");

    std::cout << "Ptr: " << ptr << " mrk: " << mrk << std::endl;

    if (ptr == mrk)
        ++mrk;
    getString("cntnt").erase(ptr, mrk - ptr);
    getRegister("mrk") = getRegister("ptr");
}

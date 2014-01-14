// Headers
#include "File.hpp"


void File::del(Sti_t &i)
{
    Sti_t
        ptr = getNumber("ptr"),
        mrk = getNumber("mrk");

    if (ptr == mrk)
        ++mrk;
    getString("cntnt").erase(ptr, mrk - ptr);

    getString("mrk") = getString("ptr");
}

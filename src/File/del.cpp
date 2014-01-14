// Headers
#include "File.hpp"


void File::del(sti &i)
{
    sti
        ptr = getNumber("ptr"),
        mrk = getNumber("mrk");

    if (ptr == mrk)
        ++mrk;
    getData("cntnt").erase(ptr, mrk - ptr);

    getData("mrk") = getData("ptr");
}

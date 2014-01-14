// Headers
#include "File.hpp"


void File::prev(sti &i)
{
    sti ptr = getNumber("ptr") - 1;
    getData("ptr") = std::to_string(ptr);
    getData("prev") = getData("cntnt")[ptr];
}

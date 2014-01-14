// Headers
#include "File.hpp"


void File::prev(Sti_t &i)
{
    Sti_t ptr = getNumber("ptr") - 1;
    getData("ptr") = std::to_string(ptr);
    getData("prev") = getData("cntnt")[ptr];
}

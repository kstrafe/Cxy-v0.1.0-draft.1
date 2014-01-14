// Headers
#include "File.hpp"


void File::prev(Sti_t &i)
{
    Sti_t ptr = getNumber("ptr") - 1;
    getRegister("ptr") = ptr;
    getString("prev") = getString("cntnt")[ptr];
}

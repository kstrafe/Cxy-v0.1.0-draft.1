// Headers
#include "File.hpp"


void File::prev(Sti_t &i)
{
    Sti_t ptr = getNumber("ptr") - 1;
    getString("ptr") = std::to_string(ptr);
    getString("prev") = getString("cntnt")[ptr];
}

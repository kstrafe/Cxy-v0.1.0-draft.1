// Headers
#include "File.hpp"


void File::prev(Sti_t &i)
{
    Sti_t ptr = getNumber(Symbol::ptr) - 1;
    getRegister(Symbol::ptr) = ptr;
    getString(Symbol::prev) = getString(Symbol::cntnt)[ptr];
}

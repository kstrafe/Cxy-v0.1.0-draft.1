// Headers
#include "File.hpp"


void File::prev(Sti_t &i)
{
    Sti_t ptr = getNumber(reg2str(Symbol::ptr)) - 1;
    getRegister(reg2str(Symbol::ptr)) = ptr;
    getString(reg2str(Symbol::prev)) = getString(reg2str(Symbol::cntnt))[ptr];
}

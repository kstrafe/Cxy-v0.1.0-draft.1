// Headers
#include "File.hpp"


void File::next(Sti_t &i)
{
    Sti_t mrk = getNumber(reg2str(Symbol::mrk)) + 1;
    getRegister(reg2str(Symbol::mrk)) = mrk;
    getString(reg2str(Symbol::next)) = getString(reg2str(Symbol::cntnt))[mrk];
}

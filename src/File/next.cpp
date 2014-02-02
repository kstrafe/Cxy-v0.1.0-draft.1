// Headers
#include "File.hpp"


void File::next(Sti_t &i)
{
    Sti_t mrk = getNumber(Symbol::mrk) + 1;
    getRegister(Symbol::mrk) = mrk;
    getString(Symbol::next) = getString(Symbol::cntnt)[mrk];
}

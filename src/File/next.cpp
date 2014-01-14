// Headers
#include "File.hpp"


void File::next(Sti_t &i)
{
    Sti_t mrk = getNumber("mrk") + 1;
    getRegister("mrk") = mrk;
    getString("next")[0] = getString("cntnt")[mrk];
}

// Headers
#include "File.hpp"


void File::next(Sti_t &i)
{
    Sti_t mrk = getNumber("mrk") + 1;
    getString("mrk") = std::to_string(mrk);
    getString("next") = getString("cntnt")[mrk];
}

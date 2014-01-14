// Headers
#include "File.hpp"


void File::next(Sti_t &i)
{
    Sti_t mrk = getNumber("mrk") + 1;
    getData("mrk") = std::to_string(mrk);
    getData("next") = getData("cntnt")[mrk];
}

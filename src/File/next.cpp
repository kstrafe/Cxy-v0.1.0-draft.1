// Headers
#include "File.hpp"


void File::next(sti &i)
{
    sti mrk = getNumber("mrk") + 1;
    getData("mrk") = std::to_string(mrk);
    getData("next") = getData("cntnt")[mrk];
}

// Headers
#include "File.hpp"


void File::capt(sti &i)
{
    m_data["capt"].back() = getData("cntnt").substr
    (
        getNumber("ptr"),
        getNumber("mrk") - getNumber("ptr")
    );
}

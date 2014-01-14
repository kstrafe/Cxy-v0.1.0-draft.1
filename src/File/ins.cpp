// Headers
#include "File.hpp"


void File::ins(sti &i)
{
    const sti pos = getNumber("ptr");

    getData("cntnt").erase
    (
        pos,
        getNumber("mrk") - pos
    );

    getData("cntnt").insert(pos, getData(m_statements[++i]));
    getData("ptr") = std::to_string(getNumber("ptr") + getData(m_statements[i]).size());
    getData("mrk") = getData("ptr");
}

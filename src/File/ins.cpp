// Headers
#include "File.hpp"


void File::ins(Sti_t &i)
{
    const Sti_t pos = getNumber("ptr");

    getString("cntnt").erase
    (
        pos,
        getNumber("mrk") - pos
    );

    getString("cntnt").insert(pos, getString(m_instructions[++i]));
    getString("ptr") = std::to_string(getNumber("ptr") + getString(m_instructions[i]).size());
    getString("mrk") = getString("ptr");
}

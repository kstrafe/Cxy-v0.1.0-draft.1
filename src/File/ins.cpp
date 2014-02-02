// Headers
#include "File.hpp"


void File::ins(Sti_t &i)
{
    const Sti_t pos = getNumber(Symbol::ptr);

    getString(Symbol::cntnt).erase
    (
        pos,
        getNumber(Symbol::mrk) - pos
    );

    getString(Symbol::cntnt).insert(pos, getString(m_instructions[++i]));
    getRegister(Symbol::ptr) = getNumber(Symbol::ptr) + getString(m_instructions[i]).size();
    getRegister(Symbol::mrk) = getNumber(Symbol::ptr);
}

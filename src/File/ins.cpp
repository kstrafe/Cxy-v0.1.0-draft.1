// Headers
#include "File.hpp"


void File::ins(Sti_t &i)
{
    const Sti_t pos = getNumber(reg2str(Symbol::ptr));

    getString(reg2str(Symbol::cntnt)).erase
    (
        pos,
        getNumber(reg2str(Symbol::mrk)) - pos
    );

    getString(reg2str(Symbol::cntnt)).insert(pos, getString(m_instructions[++i]));
    getRegister(reg2str(Symbol::ptr)) = getNumber(reg2str(Symbol::ptr)) + getString(m_instructions[i]).size();
    getRegister(reg2str(Symbol::mrk)) = getNumber(reg2str(Symbol::ptr));
}

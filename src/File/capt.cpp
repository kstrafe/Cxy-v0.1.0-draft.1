// Headers
#include "File.hpp"


void File::capt(Sti_t &i)
{
    m_data[reg2str(Symbol::capt)].back() = getString(reg2str(Symbol::cntnt)).substr
    (
        getNumber(reg2str(Symbol::ptr)),
        getNumber(reg2str(Symbol::mrk)) - getNumber(reg2str(Symbol::ptr))
    );
}

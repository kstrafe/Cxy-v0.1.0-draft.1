// Headers
#include "File.hpp"


void File::capt(Sti_t &i)
{
    m_data[reg2str(Symbol::capt)].back() = getString(Symbol::cntnt).substr
    (
        getNumber(Symbol::ptr),
        getNumber(Symbol::mrk) - getNumber(Symbol::ptr)
    );
}

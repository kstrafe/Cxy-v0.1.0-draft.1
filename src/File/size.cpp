// Headers
#include "File.hpp"


void File::size(Sti_t &i)
{
    Sti_t si = getString(m_instructions[++i]).size();
    getRegister(reg2str(Symbol::size)) = si;
}



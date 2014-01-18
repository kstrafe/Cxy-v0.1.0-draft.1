// Headers
#include  "File.hpp"


void File::drf(Sti_t &i)
{
    Sti_t pos( getNumber(m_instructions[++i]) );
    getString(reg2str(Symbol::drf))[0] = getString(reg2str(Symbol::cntnt))[pos];
}

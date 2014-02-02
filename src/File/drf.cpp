// Headers
#include  "File.hpp"


void File::drf(Sti_t &i)
{
    Sti_t pos( getNumber(m_instructions[++i]) );
    getString(Symbol::drf)[0] = getString(Symbol::cntnt)[pos];
}

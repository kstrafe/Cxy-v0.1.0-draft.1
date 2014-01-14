// Headers
#include "File.hpp"


void File::cnc(Sti_t &i)
{
    String_t &r( getString(m_instructions[++i]) );
    r.append( getString(m_instructions[++i]) );
}

// Headers
#include "File.hpp"


void File::cnc(Sti_t &i)
{
    String_t &r( getData(m_statements[++i]) );
    r.append( getData(m_statements[++i]) );
}

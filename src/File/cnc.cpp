// Headers
#include "File.hpp"


void File::cnc(sti &i)
{
    std::string &r( getData(m_statements[++i]) );
    r.append( getData(m_statements[++i]) );
}

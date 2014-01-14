// Headers
#include  "File.hpp"


void File::drf(sti &i)
{
    sti pos( getNumber(m_statements[++i]) );
    getData("drf")[0] = getData("cntnt")[pos];
}

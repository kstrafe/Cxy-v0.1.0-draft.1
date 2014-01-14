// Headers
#include  "File.hpp"


void File::drf(Sti_t &i)
{
    Sti_t pos( getNumber(m_statements[++i]) );
    getData("drf")[0] = getData("cntnt")[pos];
}

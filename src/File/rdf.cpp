// Headers
#include  "File.hpp"


void File::rdf(Sti_t &i)
{
    String_t &str( getData(m_statements[++i]) );
    str = ttl::file2str( getData(m_statements[++i]) );
}

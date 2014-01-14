// Headers
#include  "File.hpp"


void File::rdf(sti &i)
{
    std::string &str( getData(m_statements[++i]) );
    str = ttl::file2str( getData(m_statements[++i]) );
}

// Headers
#include  "File.hpp"


void File::rdf(Sti_t &i)
{
    String_t &str( getString(m_instructions[++i]) );
    str = ttl::file2str( getString(m_instructions[++i]) );
}

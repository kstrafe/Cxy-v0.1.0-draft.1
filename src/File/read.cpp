// Headers
#include "File.hpp"


void File::read()
{
    getData("cntnt") = ttl::file2str(m_file);
}

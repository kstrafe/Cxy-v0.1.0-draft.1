// Headers
#include "File.hpp"


void File::read()
{
    getString("cntnt") = ttl::file2str(m_file);
}

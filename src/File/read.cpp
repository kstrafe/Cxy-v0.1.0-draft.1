// Headers
#include "File.hpp"


void File::read()
{
    getRegister("cntnt") = ttl::file2str(m_file);
}

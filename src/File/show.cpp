// Headers
#include  "File.hpp"


void File::show(sti &i)
{
    std::cout << getData(m_statements[++i]) << std::endl;
}

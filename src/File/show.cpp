// Headers
#include  "File.hpp"


void File::show(Sti_t &i)
{
    std::cout << getData(m_statements[++i]) << std::endl;
}

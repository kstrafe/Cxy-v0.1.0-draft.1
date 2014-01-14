// Headers
#include  "File.hpp"


void File::show(Sti_t &i)
{
    std::cout << getString(m_instructions[++i]) << std::endl;
}

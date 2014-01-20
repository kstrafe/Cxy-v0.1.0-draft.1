// Headers
#include  "File.hpp"


void File::show(Sti_t &i)
{
    if (m_exec_show)
        std::cout << getString(m_instructions[i + 1]) << std::endl;
    ++i;
}

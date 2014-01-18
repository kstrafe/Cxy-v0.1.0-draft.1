// Headers
#include  "File.hpp"


void File::show(Sti_t &i)
{
    std::cout << "Showing: " << m_instructions[i + 1] << " = ";
    std::cout << getString(m_instructions[++i]) << std::endl;
}

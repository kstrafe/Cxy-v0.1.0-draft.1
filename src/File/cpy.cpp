// Headers
#include  "File.hpp"


void File::cpy(Sti_t &i)
{
//    std::cout << "Copying " << m_instructions[i + 2] << " - into: " << (int) m_instructions[i + 1][0] << std::endl;
    getRegister(m_instructions[i + 1]) = m_instructions[i + 2];
    i += 2;
}

// Headers
#include "File.hpp"


void File::size(Sti_t &i)
{
    Sti_t si = getString(m_instructions[++i]).size();
    getString("size") = std::to_string(si);
}



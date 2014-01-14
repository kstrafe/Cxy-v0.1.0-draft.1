// Headers
#include "File.hpp"


void File::size(Sti_t &i)
{
    Sti_t si = getData(m_statements[++i]).size();
    getData("size") = std::to_string(si);
}



// Headers
#include "File.hpp"


void File::size(sti &i)
{
    sti si = getData(m_statements[++i]).size();
    getData("size") = std::to_string(si);
}



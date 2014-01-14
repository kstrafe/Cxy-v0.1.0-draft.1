// Headers
#include  "File.hpp"


void File::st(sti &i)
{
    std::string &a = getData(m_statements[i + 1]),
                &b = getData(m_statements[i + 2]);
    getData("st")[0] = (a < b ? '1' : '0');
    i += 2;
}

// Headers
#include "File.hpp"


void File::trim(sti &i)
{
    std::string &r( getData(m_statements[++i]) );
    r.erase(0, r.find_first_not_of(' '));
    for (sti i = r.size() - 1; i > 0; --i)
    {
        if (r[i] == ' ')
        {
            r.pop_back();
        }
    }
    if (r.size() == 1 && r[0] == ' ')
        r.pop_back();
}

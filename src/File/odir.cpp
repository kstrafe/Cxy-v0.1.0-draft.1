// Headers
#include "File.hpp"
#include <locale>
#include <string>


void File::odir(Sti_t &i)
{
    if (m_directory_iterator != boost::filesystem::directory_iterator())
    {
        ++m_directory_iterator;
        if (m_directory_iterator != boost::filesystem::directory_iterator())
        {
            auto x = m_directory_iterator->path().native();
            std::string c(x.begin(), x.end());
            getString("odir") = c;
        }
        else
        {
            getString("odir") = "";
        }
    }
    else
    {
        getString("odir") = "";
    }
}

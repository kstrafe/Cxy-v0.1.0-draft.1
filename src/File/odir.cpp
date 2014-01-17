// Headers
#include "File.hpp"
#include <locale>
#include <string>


void File::odir(Sti_t &i)
{
    if (m_directory_iterator != boost::filesystem::directory_iterator())
    {
        getRegister("odir") = m_directory_iterator->path().generic_string();
    }
    else
    {
        getRegister("odir") = "";
    }
}

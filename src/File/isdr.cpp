// Headers
#include "File.hpp"


void File::isdr(Sti_t &i)
{
    if (m_directory_iterator != boost::filesystem::directory_iterator())
    {
        getRegister("isdr") = boost::filesystem::is_directory( getString("odir") );
    }
    else
    {
        getRegister("isdr") = 0;
    }
}

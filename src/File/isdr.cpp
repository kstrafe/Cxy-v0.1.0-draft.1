// Headers
#include "File.hpp"


void File::isdr(Sti_t &i)
{
    if (m_directory_iterator != boost::filesystem::directory_iterator())
    {
        getRegister(Symbol::isdr) = boost::filesystem::is_directory( getString(Symbol::odir) );
    }
    else
    {
        getRegister(Symbol::isdr) = 0;
    }
}

// Headers
#include "File.hpp"


void File::isdr(Sti_t &i)
{
    if (m_directory_iterator != boost::filesystem::directory_iterator())
    {
        getRegister(reg2str(Symbol::isdr)) = boost::filesystem::is_directory( getString(reg2str(Symbol::odir)) );
    }
    else
    {
        getRegister(reg2str(Symbol::isdr)) = 0;
    }
}

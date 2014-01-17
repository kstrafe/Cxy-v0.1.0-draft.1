// Headers
#include "File.hpp"


void File::extp(Sti_t &i)
{
    if (m_directory_iterator != boost::filesystem::directory_iterator())
    {
        getRegister("extp") = m_directory_iterator->path().parent_path().generic_string();
    }
    else
    {
        getRegister("extp") = "";
    }
}

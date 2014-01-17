// Headers
#include "File.hpp"


void File::adir(Sti_t &i)
{
    if (m_directory_iterator != boost::filesystem::directory_iterator())
    {
        ++m_directory_iterator;
    }
}

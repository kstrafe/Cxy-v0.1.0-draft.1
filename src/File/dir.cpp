// Headers
#include "File.hpp"


void File::dir(Sti_t &i)
{
    m_directory_iterator = boost::filesystem::directory_iterator( getString(m_instructions[++i]) );
}

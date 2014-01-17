// Headers
#include "File.hpp"


void File::updr(Sti_t &i)
{
    if (m_directory_iterator != boost::filesystem::directory_iterator())
    {
        std::string x = m_directory_iterator->path().parent_path().generic_string();

        while (x.size())
        {
            if (x.back() != '/')
            {
                x.pop_back();
            }
            else
            {
                break;
            }
        }

        getRegister("odir") = x;
        m_directory_iterator = boost::filesystem::directory_iterator( x );
    }
}

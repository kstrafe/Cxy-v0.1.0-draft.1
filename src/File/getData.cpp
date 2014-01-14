// Headers
#include "File.hpp"


std::string &File::getData(const std::string &str)
{
    return m_data[str].back();
}



const std::string &File::getData(const std::string &str) const
{
    return m_data.find(str)->second.back();
}

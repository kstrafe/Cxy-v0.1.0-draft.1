// Headers
#include "File.hpp"


File::sti File::getNumber(const std::string &str)
{
    return std::atoi(m_data[str].back().data());
}

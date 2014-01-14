// Headers
#include "File.hpp"


std::ostream &operator<<(std::ostream &os, const File &file)
{
    os << file.getString("cntnt");
    return os;
}

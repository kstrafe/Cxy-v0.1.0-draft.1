// Headers
#include "File.hpp"


std::ostream &operator<<(std::ostream &os, const File &file)
{
    os << file.getData("cntnt");
    return os;
}

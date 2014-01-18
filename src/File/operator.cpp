// Headers
#include "File.hpp"


std::ostream &operator<<(std::ostream &os, const File &file)
{
    os << file.getString(file.m_id[File::Sti_t(file.m_runstate)][File::Sti_t(File::Symbol::cntnt)]);
    return os;
}

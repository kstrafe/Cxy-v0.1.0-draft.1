// Headers
#include "File.hpp"


std::ostream &operator<<(std::ostream &os, const File &file)
{
    std::string &to_write = (std::string &) file.getString(file.m_id[File::Sti_t(File::Runstate::Execute)][File::Sti_t(File::Symbol::cntnt)]);
    os << to_write.substr(0, to_write.size() - 1);
    return os;
}

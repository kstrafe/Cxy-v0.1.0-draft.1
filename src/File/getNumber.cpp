// Headers
#include "File.hpp"


auto File::getNumber(const String_t &str) -> Sti_t
{
    return std::atoi(m_data[str].back().data());
}

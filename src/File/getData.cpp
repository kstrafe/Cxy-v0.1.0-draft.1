// Headers
#include "File.hpp"


auto File::getData(const String_t &str) -> String_t &
{
    return m_data[str].back();
}



auto File::getData(const String_t &str) const -> const String_t &
{
    return m_data.find(str)->second.back();
}

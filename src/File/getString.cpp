// Headers
#include "File.hpp"


auto File::getString(const Symbol sym) -> String_t &
{
    return getString(reg2str(sym));
}


auto File::getString(const Symbol sym) const -> const String_t &
{
    return getString(reg2str(sym));
}


auto File::getString(const String_t &str) -> String_t &
{
    return m_data[str].back();
}


auto File::getString(const String_t &str) const -> const String_t &
{
    return m_data.find(str)->second.back();
}

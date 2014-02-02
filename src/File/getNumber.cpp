// Headers
#include "File.hpp"


auto File::getNumber(const Symbol sym) -> Sti_t
{
    return getNumber(reg2str(sym));
}


auto File::getNumber(const Symbol sym) const -> Sti_t
{
    return getNumber(reg2str(sym));
}


auto File::getNumber(const String_t &str) -> Sti_t
{
    return m_data[str].back();
}


auto File::getNumber(const String_t &str) const -> Sti_t
{
    return m_data.find(str)->second.back();
}

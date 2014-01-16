// Headers
#include "File.hpp"


auto File::getRegister(const String_t &str) -> Register_t &
{
    return m_data[str].back();
}


auto File::getRegister(const String_t &str) const -> const Register_t &
{
    return m_data.find(str)->second.back();
}

// Headers
#include "Register.hpp"


Register::Register()
:
    last(Last::String),
    m_string("")
{}


Register::Register(const std::string &s)
:
    last(Last::String),
    m_string(s)
{}


Register::Register(std::string &&s)
:
    last(Last::String),
    m_string(std::move(s))
{}


Register::Register(const std::size_t &s)
:
    last(Last::String),
    m_number(s)
{}


Register::Register(std::size_t &&s)
:
    last(Last::Number),
    m_number(std::move(s))
{}


Register::operator std::size_t()
{
    if (last == Last::String)
    {
        m_number = std::atoll(m_string.data());
        last = Last::Both;
    }
    return m_number;
}


Register::operator std::size_t() const
{
    if (last == Last::String)
    {
        m_number = std::atoll(m_string.data());
        last = Last::Both;
    }
    return m_number;
}


Register::operator std::string &()
{
    if (last == Last::Number)
    {
        m_string = std::to_string(m_number);
        last = Last::String;
    }
    return m_string;
}


Register::operator const std::string &() const
{
    if (last == Last::Number)
    {
        m_string = std::to_string(m_number);
        last = Last::Both;
    }
    return m_string;
}


Register &Register::operator=(std::size_t n)
{
    m_number = n;
    last = Last::Number;
    return *this;
}


Register &Register::operator=(const std::string &s)
{
    m_string = s;
    last = Last::String;
    return *this;
}

Register &Register::operator=(const Register &r)
{
    m_string = r.m_string;
    last = r.last;
    m_number = r.m_number;
}

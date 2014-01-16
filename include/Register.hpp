#ifndef REGISTER_HPP_INCLUDED
#define REGISTER_HPP_INCLUDED

// Headers
#include <string>
#include <cstddef>


class Register
{
public:

    Register()
    :
        last(Last::String),
        m_string("")
    {}
    Register(const std::string &s)
    :
        last(Last::String),
        m_string(s)
    {}
    Register(std::string &&s)
    :
        last(Last::String),
        m_string(std::move(s))
    {}
    Register(const std::size_t &s)
    :
        last(Last::String),
        m_number(s)
    {}
    Register(std::size_t &&s)
    :
        last(Last::Number),
        m_number(std::move(s))
    {}
    ~Register() = default;

    operator std::size_t()
    {
        if (last == Last::String)
        {
            m_number = std::atoll(m_string.data());
            last = Last::Both;
        }
        return m_number;
    }
    operator std::size_t() const
    {
        if (last == Last::String)
        {
            m_number = std::atoll(m_string.data());
            last = Last::Both;
        }
        return m_number;
    }
    operator std::string &()
    {
        if (last == Last::Number)
        {
            m_string = std::to_string(m_number);
            last = Last::String;
        }
        return m_string;
    }
    operator const std::string &() const
    {
        if (last == Last::Number)
        {
            m_string = std::to_string(m_number);
            last = Last::Both;
        }
        return m_string;
    }
    Register &operator=(std::size_t n)
    {
        m_number = n;
        last = Last::Number;
        return *this;
    }
    Register &operator=(const std::string &s)
    {
        m_string = s;
        last = Last::String;
        return *this;
    }

private:

    enum class Last
    {
        String,
        Number,
        Both
    }
    mutable last;

    mutable std::string m_string;
    mutable std::size_t m_number;

};

#endif // REGISTER_HPP_INCLUDED

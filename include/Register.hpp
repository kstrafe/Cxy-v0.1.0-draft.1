#ifndef REGISTER_HPP_INCLUDED
#define REGISTER_HPP_INCLUDED

// Headers
#include <string>
#include <cstddef>


class Register
{
public:

    Register();

    Register(const std::string &s);
    Register(std::string &&s);
    Register(const std::size_t &s);
    Register(std::size_t &&s);

    ~Register() = default;

    operator std::size_t();
    operator std::size_t() const;
    operator std::string &();
    operator const std::string &() const;
    Register &operator=(std::size_t n);
    Register &operator=(const std::string &s);
    Register &operator=(const Register &r);

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

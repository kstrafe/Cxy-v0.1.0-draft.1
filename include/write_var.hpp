#ifndef WRITE_VAR_HPP_INCLUDED
#define WRITE_VAR_HPP_INCLUDED

// Headers
#include <fstream>
#include <type_traits>
#include <limits>


template <typename T, typename BYTE = unsigned char>
void write_var(std::fstream &stream, T variable)
{
    static_assert(std::is_signed<T>::value == false, "Value must be unsigned");

    constexpr const BYTE ZERO_BITTED = std::numeric_limits<BYTE>::max() / 2;
    constexpr const BYTE ONE_BITTED = ZERO_BITTED + 1;

    loop:
    {
        if ((variable & ~ZERO_BITTED) == 0)
        {
            stream.put(static_cast<BYTE>(variable));
            return;
        }
        else
        {
            stream.put(static_cast<BYTE>((variable & ZERO_BITTED) | ONE_BITTED));
            variable >>= 7;
        }
    }
    goto loop;
}


#endif // WRITE_VAR_HPP_INCLUDED

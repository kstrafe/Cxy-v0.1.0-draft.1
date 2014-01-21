#ifndef READ_VAR_HPP_INCLUDED
#define READ_VAR_HPP_INCLUDED

// Headers
#include <istream>
#include <type_traits>
#include <stdexcept>
#include <limits>
#include <boost/integer.hpp>


template <typename T, typename BYTE = unsigned char>
T read_var(std::istream &stream)
{
    static_assert(std::is_signed<T>::value == false, "Value must be unsigned");

    constexpr const BYTE ZERO_BITTED = std::numeric_limits<BYTE>::max() / 2;
    constexpr const BYTE ONE_BITTED = ZERO_BITTED + 1;
    constexpr const std::size_t BIT_COUNT = std::numeric_limits<T>::digits;

    BYTE theByte;
    typename boost::int_min_value_t<BIT_COUNT>::fast shift = 0;
    T result = 0;

    while (shift < BIT_COUNT)
    {
        if (stream.eof())
        {
            throw std::out_of_range
            (
                "read_var: Unable to read variadic length integer from the stream, "
                + std::to_string(shift / 7)
                + " bytes were read, but no terminating bit was found.");
        }
        theByte = stream.get();
        result |= static_cast<T>(theByte & ZERO_BITTED) << shift;
        if ((theByte & ONE_BITTED) == 0)
        {
            return result;
        }
        shift += 7;
    }
    throw std::out_of_range("read_var: Unable to read variadic length integer from the stream, all the bytes have been consumed without a terminal bit being present.");
}


#endif // READ_VAR_HPP_INCLUDED

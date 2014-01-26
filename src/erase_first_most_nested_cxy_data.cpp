// Headers
#include <string>
#include <iostream>
typedef std::size_t Sti_t;
extern std::pair<Sti_t, Sti_t> get_first_most_nested_position(const std::string &content);


void erase_first_most_nested_cxy_data(std::string &content)
{
    constexpr const Sti_t ADDITIONAL_LENGTH = sizeof("#cxy stox") / sizeof(char);

    std::pair<Sti_t, Sti_t> most_nested = get_first_most_nested_position(content);
    if (most_nested.first != std::string::npos && most_nested.second != std::string::npos)
    {
        content.erase(most_nested.first, most_nested.second - most_nested.first + ADDITIONAL_LENGTH);
    }
    else if (most_nested.first != std::string::npos)
    {
        content.erase(most_nested.first, sizeof("#cxy starx"));
    }
}

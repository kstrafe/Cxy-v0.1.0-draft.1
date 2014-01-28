// Headers
#include <string>
#include <iostream>
typedef std::size_t Sti_t;
extern std::pair<Sti_t, Sti_t> get_first_most_nested_position(const std::string &content);


std::string erase_all_cxy_statements(const std::string &content)
{
    constexpr const Sti_t ADDITIONAL_LENGTH = sizeof("#cxy stox") / sizeof(char);

//    std::cout << "We're erasing from: " << content << std::endl;
    std::string return_copy = content;
    std::pair<Sti_t, Sti_t> most_nested = get_first_most_nested_position(content);
//    std::cout << "Erase all cxy statements: " << most_nested.first << ", " << most_nested.second << "\n\n";

    while (most_nested.first != std::string::npos)
    {
        return_copy.erase(most_nested.first, most_nested.second - most_nested.first + ADDITIONAL_LENGTH);
        most_nested = get_first_most_nested_position(return_copy);
    }

    return return_copy;
}

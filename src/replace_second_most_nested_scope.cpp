// Headers
#include <string>
#include <iostream>
typedef std::size_t Sti_t;
extern std::pair<Sti_t, Sti_t> get_first_most_nested_position(const std::string &content);
extern Sti_t erase_second_most_nested_scope(std::string &content);


void replace_second_most_nested_scope(std::string &content, std::string &with)
{
    Sti_t position = erase_second_most_nested_scope(content);
    content.insert(position, with);

//    std::cout << "REPLCNT: " << content << "///////////////////////////////////////////////////////////\n\n";
//    content.insert(position, with);
//    std::pair<Sti_t, Sti_t> most_nested = get_first_most_nested_position(content);
//    if (most_nested.first != std::string::npos)
//    {
//        content.erase(most_nested.first, most_nested.second - most_nested.first + ADDITIONAL_LENGTH);
//    }
}

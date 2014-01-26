// Headers
#include <string>
#include <TTL/TTL.hpp>
#include <iostream>
typedef std::size_t Sti_t;
extern std::pair<Sti_t, Sti_t> get_second_most_nested_position(const std::string &content);
extern Sti_t get_closing_stop(const std::string &content, Sti_t stox);


Sti_t erase_second_most_nested_scope(std::string &content)
{
    std::pair<Sti_t, Sti_t> most_nested = get_second_most_nested_position(content);
    most_nested.first += sizeof("#cxy starx");
    std::string to_operate = content.substr(most_nested.first, most_nested.second - most_nested.first);

    std::string all_cxys;
//    std::cout << "To Operate: " << to_operate;

    Sti_t starx = to_operate.find("#cxy star");
    Sti_t stox = get_closing_stop(to_operate, starx);

    while (starx != stox && starx != std::string::npos && stox != std::string::npos)
    {
        all_cxys.append(to_operate.substr(starx, stox - starx + sizeof("#cxy stox")));
//        std::cout << "Cxys: " << to_operate.substr(starx, stox - starx + sizeof("#cxy stox")) << "===============================================\n\n";
        to_operate.erase(starx, stox - starx + sizeof("#cxy stox"));
//        std::cout << "TO OP: " << to_operate << "===============================================\n\n";

        starx = to_operate.find("#cxy star");
        stox = get_closing_stop(to_operate, starx);
    }

    content.erase(most_nested.first, most_nested.second - most_nested.first);

    std::cout << "Generated content1: " << content;

    content.insert(most_nested.first, all_cxys);

    std::cout << "Generated content3: " << content;

    return most_nested.first;
}

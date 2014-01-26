// Headers
#include <string>
#include <iostream>
typedef std::size_t Sti_t;


std::string get_second_most_nested_data(const std::string &content)
{
    Sti_t deepest_stop = content.find("#cxy sto");
    Sti_t deepest_start = content.rfind("#cxy star", deepest_stop);

    Sti_t second_deepest_stop = content.find("#cxy sto", deepest_stop + 1);
    Sti_t second_deepest_start = content.rfind("#cxy star", deepest_start - 1);

    Sti_t start_between = content.find("#cxy star", deepest_stop);

    while (start_between != std::string::npos && start_between < second_deepest_stop)
    {
        start_between = content.find("#cxy star", start_between + 1);
        second_deepest_stop = content.find("#cxy sto", second_deepest_stop + 1);
    }

    // Knowing that deepest_start points to the position before #, we must add the entire length:
    second_deepest_start += sizeof("#cxy starx\n") / sizeof(char);
    // x can be 'b' or 't'

    if (second_deepest_start != std::string::npos && second_deepest_stop != std::string::npos)
        return content.substr(second_deepest_start, second_deepest_stop - second_deepest_start);
    else
        return content;
}

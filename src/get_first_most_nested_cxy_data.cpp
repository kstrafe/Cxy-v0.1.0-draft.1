// Headers
#include <string>
#include <iostream>
typedef std::size_t Sti_t;


std::string get_first_most_nested_cxy_data(const std::string &content)
{
    Sti_t deepest_stop = content.find("#cxy sto");
    Sti_t deepest_start = content.rfind("#cxy star", deepest_stop);

    // Knowing that deepest_start points to the position before #, we must add the entire length:
    deepest_start += sizeof("#cxy starx") / sizeof(char);
    // x can be 'b' or 't'

    return content.substr(deepest_start, deepest_stop - deepest_start);
}

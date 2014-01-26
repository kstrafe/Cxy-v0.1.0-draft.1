// Headers
#include <string>
#include <utility>
typedef std::size_t Sti_t;


std::pair<Sti_t, Sti_t> get_first_most_nested_position(const std::string &content)
{
    Sti_t deepest_stop = content.find("#cxy sto");
    Sti_t deepest_start = content.rfind("#cxy star", deepest_stop);

    return std::make_pair(deepest_start, deepest_stop);
}

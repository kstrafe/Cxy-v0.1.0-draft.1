// Headers
#include <string>
#include <utility>
typedef std::size_t Sti_t;


std::pair<Sti_t, Sti_t> get_second_most_nested_position(const std::string &content)
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

    return std::make_pair(second_deepest_start, second_deepest_stop);
}

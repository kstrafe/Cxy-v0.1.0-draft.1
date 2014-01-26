// Headers
#include <string>
typedef std::size_t Sti_t;


/**
    \return position of the string "#cxy stox" that matches with the input's first "#cxy starx" from position.
*/
Sti_t get_closing_stop(const std::string &content, Sti_t start)
{
    start = content.find("#cxy star", start + 1);
    Sti_t stop = content.find("#cxy sto");

    while (start != std::string::npos && start < stop)
    {
        start = content.find("#cxy star", start + 1);
        stop = content.find("#cxy sto", stop + 1);
    }

    return stop;
}

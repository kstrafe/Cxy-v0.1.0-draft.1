// Headers
#include <string>
typedef std::size_t Sti_t;


/**
    \return position of the string "#cxy starx" that matches with the input's first "#cxy stox" from position.
*/
Sti_t get_closing_start(const std::string &content, Sti_t stox)
{
    stox = content.rfind("#cxy star", stox);
    Sti_t stop = content.rfind("#cxy sto", stox);

    while (stox != std::string::npos && stox < stop)
    {
        stox = content.rfind("#cxy star", stox - 1);
        stop = content.rfind("#cxy sto", stox);
    }

    return stop;
}

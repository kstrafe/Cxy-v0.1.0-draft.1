// Headers
#include "File.hpp"


void File::parse()
{
    static constexpr const sti REMAINING_LAST = 1, DELIMITING_CHAR = 1, END_OF_EXPRESSION = 8;

    sti start = getData("cntnt").find("#cxy start");
    while (start != getData("cntnt").npos)
    {
        ttl::ScopedFunction retry_find
        (
            [&start, this]()
            {
                start = getData("cntnt").find("#cxy start");
            }
        );

        sti end = start + sizeof("#cxy start") / sizeof(char) - DELIMITING_CHAR;
        sti stop = parseStatements(end);
        // Remove "#cxy start - X - #cxy stop" sequence.
        getData("cntnt").erase(start, (stop - start + END_OF_EXPRESSION) + REMAINING_LAST);
    }
}

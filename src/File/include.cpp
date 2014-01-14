// Headers
#include "File.hpp"


void File::include()
{
    static constexpr const sti REMAINING_LAST_TWO = 2, DELIMITING_CHAR = 1;

    sti start = getData("cntnt").find("#cxy <");
    while (start != getData("cntnt").npos)
    {
        ttl::ScopedFunction retry_find
        (
            [&start, this]()
            {
                start = getData("cntnt").find("#cxy <");
            }
        );

        sti end = start + (sizeof("#cxy <") / sizeof(char)) - DELIMITING_CHAR;

        sti ending = end, length = 0;
        for (; getData("cntnt")[ending] != '>'; ++ending, ++length);
        std::string include_name(getData("cntnt").substr(end, length)); // Get include file's name

        getData("cntnt").erase(start, (ending - start) + REMAINING_LAST_TWO); // Need to remove the "#cxy <file>" string

        // INCLUDE AT START
//        getData("cntnt").insert(start, ttl::file2str(include_name)); // Place the file there instead
        // INCLUDE AT END
        getData("cntnt").insert(getData("cntnt").size(), ttl::file2str(include_name));
    }
}

// Headers
#include "File.hpp"


void File::include()
{
    static constexpr const Sti_t REMAINING_LAST_TWO = 2, DELIMITING_CHAR = 1;

    Sti_t start = getString("cntnt").find("#cxy <");
    while (start != getString("cntnt").npos)
    {
        ttl::ScopedFunction retry_find
        (
            [&start, this]()
            {
                start = getString("cntnt").find("#cxy <");
            }
        );

        Sti_t end = start + (sizeof("#cxy <") / sizeof(char)) - DELIMITING_CHAR;

        Sti_t ending = end, length = 0;
        for (; getString("cntnt")[ending] != '>'; ++ending, ++length);
        String_t include_name(getString("cntnt").substr(end, length)); // Get include file's name

        getString("cntnt").erase(start, (ending - start) + REMAINING_LAST_TWO); // Need to remove the "#cxy <file>" String_t

        // INCLUDE AT START
        getString("cntnt").insert(start, ttl::file2str(include_name)); // Place the file there instead
        // INCLUDE AT END
//        getString("cntnt").insert(getString("cntnt").size(), ttl::file2str(include_name));
    }
}

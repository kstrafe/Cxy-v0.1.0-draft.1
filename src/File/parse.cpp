// Headers
#include "File.hpp"


void File::parse()
{
    // I could simply create a substr of all non #cxy enclosed statements.
    static constexpr const Sti_t REMAINING_LAST = 1, DELIMITING_CHAR = 1, END_OF_EXPRESSION = 8;
//
    Sti_t start = getString("cntnt").find("#cxy start"); // Find the first invocation...
    while (start != getString("cntnt").npos)
    {
        ttl::ScopedFunction retry_find
        (
            [&start, this]()
            {
                start = getString("cntnt").find("#cxy start");
            }
        );

        Sti_t end = start + sizeof("#cxy start") / sizeof(char) - DELIMITING_CHAR;
        Sti_t stop = parseStatements(end);
        // Remove "#cxy start - X - #cxy stop" sequence.
        std::cout << "ENDING PARSING WITH DATA BUFFER:\n" << getString("cntnt") << "\nEND\n";
        getString("cntnt").erase(start, (stop - start + END_OF_EXPRESSION) + REMAINING_LAST);
        std::cout << "ENDING ERASING WITH DATA BUFFER:\n" << getString("cntnt") << "\nEND\n";
    }

//    Sti_t start = getString("cntnt").find("#cxy start");
//    parseStatements(start + sizeof("#cxy start") / sizeof(char) - DELIMITING_CHAR);
}


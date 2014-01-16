// Headers
#include "File.hpp"


void File::parse()
{
    static constexpr const Sti_t REMAINING_LAST = 1, DELIMITING_CHAR = 1, END_OF_EXPRESSION = 8;

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

//        std::cout << "RIGHT AFTER FOUND:\n" << getString("cntnt") << "\nEND\n";

        Sti_t end = start + sizeof("#cxy start") / sizeof(char) - DELIMITING_CHAR;
        Sti_t stop = parseStatements(end);
        // Remove "#cxy start - X - #cxy stop" sequence from content.
//        std::cout << "ENDING PARSING WITH DATA BUFFER:\n" << getString("cntnt") << "\nEND\n";
//        std::cout << "PARSING\n";
        getString("cntnt").erase(start, (stop - start + END_OF_EXPRESSION) + REMAINING_LAST);
//        std::cout << "ENDING ERASING WITH DATA BUFFER:\n" << getString("cntnt") << "\nEND\n";

//        for (auto &x : m_instructions)
//        {
//            std::cout << "Parsed Instruction: " << x << "\n";
//        }
    }

//    Sti_t start = getString("cntnt").find("#cxy start");
//    parseStatements(start + sizeof("#cxy start") / sizeof(char) - DELIMITING_CHAR);
}


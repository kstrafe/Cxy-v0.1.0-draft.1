// Headers
#include "File.hpp"
#include <boost/tokenizer.hpp>


/*
    Parse all the #cxy statements from the file.
    Binary nestings must run before the previous nest.
*/
void File::parse()
{
    static constexpr const Sti_t REMAINING_LAST = 1, DELIMITING_CHAR = 1, END_OF_EXPRESSION = 8;

    // We start by parsing tokens:

//    Sti_t binary = getString("cntnt").find("#cxy starb\n");
//    if (binary != std::string::npos)
//    {
//        Sti_t end = parseBinaryStatements(binary + sizeof("#cxy starb\n") - DELIMITING_CHAR);
//        std::cout << "End is at: " << end << std::endl;
//        getRegister("cntnt") = getString("cntnt").erase(0, end);
//
//        std::cout << "Before execution content: " << getString("cntnt") << "\n\n";
//    }
//    else
    {
        Sti_t start = getString("cntnt").find("#cxy start"); // Find the first invocation...
        // No, let's just start tokenizing...
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
}


// Headers
#include "File.hpp"


void File::include()
{
    try
    {
        static constexpr const Sti_t REMAINING_LAST_ONE = 1, DELIMITING_CHAR = 1;

        Sti_t start = getString(m_id[Sti_t(Runstate::Execute)][Sti_t(Symbol::cntnt)]).find("#cxy <");
        while (start != getString(m_id[Sti_t(Runstate::Execute)][Sti_t(Symbol::cntnt)]).npos)
        {
            ttl::ScopedFunction retry_find
            (
                [&start, this]()
                {
                    start = getString(m_id[Sti_t(Runstate::Execute)][Sti_t(Symbol::cntnt)]).find("#cxy <");
                }
            );

            Sti_t end = start + (sizeof("#cxy <") / sizeof(char)) - DELIMITING_CHAR;

            Sti_t ending = end, length = 0;
            for (; getString(m_id[Sti_t(Runstate::Execute)][Sti_t(Symbol::cntnt)])[ending] != '>'; ++ending, ++length);
            String_t include_name(getString(m_id[Sti_t(Runstate::Execute)][Sti_t(Symbol::cntnt)]).substr(end, length)); // Get include file's name

            getString(m_id[Sti_t(Runstate::Execute)][Sti_t(Symbol::cntnt)]).erase(start, (ending - start) + REMAINING_LAST_ONE); // Need to remove the "#cxy <file>" String_t

            // INCLUDE AT START
            getString(m_id[Sti_t(Runstate::Execute)][Sti_t(Symbol::cntnt)]).insert(start, ttl::file2str(include_name)); // Place the file there instead
            // INCLUDE AT END
    //        getString("cntnt").insert(getString("cntnt").size(), ttl::file2str(include_name));
        }

    }
    catch (std::exception &e)
    {
        std::cout << "Error during inclusion: " << e.what();
        throw;
    }
}

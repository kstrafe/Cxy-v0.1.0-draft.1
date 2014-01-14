// Headers
#include "File.hpp"


auto File::parseStatements(Sti_t position) -> Sti_t
{
    if (getString("cntnt")[position++] == '\n')
    {
        while (true)
        {
            String_t statement(std::move(getNextArgument(getString("cntnt"), position)));
            if (statement.size() == 0)
            {
                return position;
            }
            else
            {
                m_instructions.emplace_back(std::move(statement));
            }
        }
    }
    else
    {
        throw std::runtime_error("#cxy start must be superseded by a new line.");
    }
    return position;
}

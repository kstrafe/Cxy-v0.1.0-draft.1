// Headers
#include "File.hpp"


File::sti File::parseStatements(sti position)
{
    if (getData("cntnt")[position++] == '\n')
    {
        while (true)
        {
            std::string statement(std::move(getNextArgument(getData("cntnt"), position)));
            if (statement.size() == 0)
            {
                return position;
            }
            else
            {
                m_statements.emplace_back(std::move(statement));
            }
        }
    }
    else
    {
        throw std::runtime_error("#cxy start must be superseded by a new line.");
    }
    return position;
}

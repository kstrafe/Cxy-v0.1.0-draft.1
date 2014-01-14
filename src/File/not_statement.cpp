// Headers
#include  "File.hpp"


void File::not_statement(Sti_t &i)
{
    getData("not") = std::to_string(!getNumber(m_statements[i + 1]));
    ++i;
}

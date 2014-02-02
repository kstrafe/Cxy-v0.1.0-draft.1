// Headers
#include "File.hpp"
#include <boost/regex.hpp>


void File::repl(Sti_t &i)
{
    boost::regex regular_expression(getString(m_instructions[i + 1]));
    std::string &replacement(getString(m_instructions[i + 2]));
    std::string &content(getString(Symbol::cntnt));
    content = boost::regex_replace(content, regular_expression, replacement);

    i += 2;
}

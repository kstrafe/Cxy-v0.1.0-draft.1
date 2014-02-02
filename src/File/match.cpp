// Headers
#include "File.hpp"
#include <boost/regex.hpp>


/*
    match - takes in 1 argument, a regular expression.
    This regular expression will be checked for existence against the substring
    between [ptr, mrk) of cntnt. If it exists. "match" register will
    be set to true, else it will be set to false.

    match uses boost::regex_match internally to match.
    No extra flags are appended to the regular expression.
*/
void File::match(Sti_t &i)
{
    boost::regex regular_expression(getString(m_instructions[i + 1]));
    std::string &content(getString(Symbol::cntnt));
    getRegister(Symbol::match) = boost::regex_match(content, regular_expression);

    i += 1;
}

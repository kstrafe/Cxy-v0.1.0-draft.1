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
    std::cout << "Trying to match content\n";
    boost::regex reg1(getString(m_instructions[i + 1]));

    // Let's check if regex works:
    std::string &ref(getString(reg2str(Symbol::cntnt)));

//    std::cout << "String: " << ref << std::endl << "Regexp: " << reg1.str() << std::endl;

    getRegister(reg2str(Symbol::match)) = boost::regex_match(ref, reg1);

    i += 1;
}

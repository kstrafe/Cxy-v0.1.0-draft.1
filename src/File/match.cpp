// Headers
#include "File.hpp"
#include <boost/regex.hpp>


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

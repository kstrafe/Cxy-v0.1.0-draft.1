// Headers
#include "File.hpp"
#include <boost/regex.hpp>


void File::repl(Sti_t &i)
{
    std::cout << "Assigning regex\n";
    boost::regex reg1(getString(m_instructions[i + 1]));
    boost::regex reg2(getString(m_instructions[i + 2]));

    // Let's check if regex works:
    std::string &ref(getString(reg2str(Symbol::cntnt)));

//    std::cout << "String: " << ref << std::endl << "Regexp: " << reg1.str() << std::endl;

    ref = boost::regex_replace(ref, reg1, reg2);

    i += 2;
}

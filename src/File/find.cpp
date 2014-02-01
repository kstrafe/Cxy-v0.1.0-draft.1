// Headers
#include "File.hpp"


void File::find(Sti_t &i)
{
    Sti_t
        ptr = getNumber(reg2str(Symbol::ptr)),
        mrk = getNumber(reg2str(Symbol::mrk));



    String_t &tosrch(getString(m_instructions[++i]));
//    std::cout << "trying to find'" << tosrch << "'\n";
//    std::cout << "ptr's val:" << ptr << std::endl;
//    std::cout << "mrk's val:" << mrk << std::endl;

    Sti_t occurrence = 0, last = ptr - (ptr > 0 ? 1 : 0);

    if (ptr == mrk) // Unrestricted area (from pointer to file end)
    {
//        std::cout << "read content: " << getString(reg2str(Symbol::cntnt)) << "\n";
//        std::cout << "to search: " << tosrch << "\n";
        if ((last = getString(reg2str(Symbol::cntnt)).find(tosrch, (ptr > 0 ? ++last : last))) != getString(reg2str(Symbol::cntnt)).npos)
        {
//            std::cout << "Logic error?\n";
            ptr = last;
            getRegister(reg2str(Symbol::mrk)) = last + tosrch.size()/* - (ptr > 0 ? 0 : 1)*/;
            getRegister(reg2str(Symbol::ptr)) = ptr;
        }
    }
    else // Restricted area (from pointer till marker)
    {
        if ((last = getString(reg2str(Symbol::cntnt)).find(tosrch, (ptr > 0 ? ++last : last))) != getString(reg2str(Symbol::cntnt)).npos)
        {
            if (last + tosrch.size() < mrk)
            {
                ptr = last;
                getRegister(reg2str(Symbol::mrk)) = last + tosrch.size();
                getRegister(reg2str(Symbol::ptr)) = ptr;
            }
        }
    }

    std::string blaat = "trolol \
    dasd \
    control";
}

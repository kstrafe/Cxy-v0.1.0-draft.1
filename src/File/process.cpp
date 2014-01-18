

// Headers
#include "File.hpp"


void File::process()
{
    read();
    include();
    parse();

    if (m_runstate == Runstate::Interpret)
    {
        interpret();
    }
    else
    {
        compile();
        execute();
    }
}

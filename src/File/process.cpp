

// Headers
#include "File.hpp"


void File::process()
{
    read();
    include();
    parse();
    interpret();
    execute();
}

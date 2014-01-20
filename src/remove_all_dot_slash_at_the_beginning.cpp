// Headers
#include <string>


// "./" - "This working directory".
void remove_all_dot_slash_at_the_beginning(std::string &path)
{
    if (path.find("./") == 0)
    {
        do
        {
            path.erase(0, 2);
        }
        while (path.find("./") == 0);
    }
}

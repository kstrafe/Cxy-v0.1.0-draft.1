// Headers
#include <string>
#include <iostream>


// "/../" - "The directory one up the hierarchy".
void get_non_dot_dot_path(std::string &path)
{
    // The path is on the form: X:/A/B/C/../../D/E/F
    // We want: X:/D/E/F
    typedef std::size_t Sti_t;
    Sti_t i = path.find("/../");
    while (i != std::string::npos)
    {
        // Find the prev folder:
        Sti_t ps = i - 1;
        while (true)
        {
            if (path[ps] == '/')
            {
                break;
            }
            --ps;
        }
        path.erase(ps, (i + 3) - ps);
        i = path.find("/../");
        std::cout << path << std::endl;
    }
}

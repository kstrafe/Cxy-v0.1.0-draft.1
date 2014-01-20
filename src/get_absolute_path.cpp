// Headers
#include <string>
#include <boost/filesystem.hpp>


std::string get_absolute_path(std::string &working_directory, std::string &relative_path)
{
    if (relative_path.find("../") == 0) // Ouch!
    {
        boost::filesystem::path tmp = working_directory;
        std::string tmp2 = relative_path;
        do
        {
            tmp = tmp.parent_path();
            std::string x = tmp.generic_string();
//            x.erase(x.find_last_of('/'));
//            tmp = x;
            tmp2.erase(0, 3);
        }
        while (tmp2.find("../") == 0);
        tmp2 = tmp.generic_string() + "/" + tmp2;
        return tmp2;
//                    throw std::invalid_argument("Unable to parse ../");
    }
    else
    {
        return working_directory + relative_path;
    }
}

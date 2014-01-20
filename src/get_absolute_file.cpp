// Headers
#include <string>
#include <boost/filesystem.hpp>
extern std::string get_absolute_path(std::string &, std::string &);


std::string get_absolute_file(std::string &working_directory, std::string &operand)
{
    boost::filesystem::path p = operand;
    std::string pd = p.generic_string();
    std::string ret;

    if (p.is_relative())
    {
        std::cout << "This file is relative\n";
        ret = get_absolute_path(working_directory, pd);
        std::cout << "Returned: " << ret << "\n";
    }
    else
    {
        ret = operand;
    }
    return ret;
}

// Headers
#include <string>
#include <boost/filesystem.hpp>


std::string get_relative_to(const boost::filesystem::path path, const boost::filesystem::path base)
{
    if (path.has_root_path())
    {
        if (path.root_path() != base.root_path())
        {
            return path.generic_string();
        }
        else
        {
            return get_relative_to(path.relative_path(), base.relative_path());
        }
    }
    else
    {
        if (base.has_root_path())
        {
            throw "cannot uncomplete a path relative path from a rooted base";
        }
        else
        {
            typedef boost::filesystem::path::const_iterator path_iterator;
            path_iterator path_it = path.begin();
            path_iterator base_it = base.begin();
            while ( path_it != path.end() && base_it != base.end() ) {
                if (*path_it != *base_it) break;
                ++path_it; ++base_it;
            }
            boost::filesystem::path result;
            for (; base_it != base.end(); ++base_it)
            {
                result /= "..";
            }
            for (; path_it != path.end(); ++path_it)
            {
                result /= *path_it;
            }
            std::string res(result.generic_string());
            res.erase(0, 3);
            return res;
        }
    }
}

#include <TTL/TTL.hpp>
#include "File.hpp"
#include "Register.hpp"



int main(int argc, char *argv[])
{
    std::string workdir = boost::filesystem::current_path().generic_string();

    if (argc == 1)
    {
        std::cout
            << "Error: No input file(s) specified.\n"
            << "Enter \"cxy --help\" without quotation marks for help.";
        return 0;
    }

    ttl::Argument a(argc, argv); // Store arguments globally

    // We get a file as an argument, we must find out if the file contains either:
    // #cxy <filename>
    // or
    // #cxy start
    // and
    // #cxy end
    /*
        The first case will include the cxy file, which contains #cxy start and #cxy end.
        if:
            #cxy <file>
            #cxy start
            cxy code
            #cxy end

        , then the most locally scoped #cxy start gets precedence.
        The above first executes start-end sequence before it copies the file.
        The order should be:

        3 #cxy <file>
        2 #cxy <file2>
        1 #cxy start
        0 #cxy start

        The cxy directive most down in the chain should get precedence.
        Problem: if file2 includes another #cxy, then we will get:

        4 #cxy <file>
        3 #cxy <file3> // file2's code
        2 #cxy start // file2's code
        1 #cxy start
        0 #cxy start

        I think this is wrong, because it would include file3 and so on: which may refer to an assembly
        preprocessor! We can not simply put assembly in raw code? It could happen that
        file contained C++ code changes, and file3 definitions for a ful assembly generation.
        File2 also contained normal C++ code, how can we resolve this?

        Let's concern us with a single include first, and a single command sequence.
    */

//    std::fstream output("out", std::ios::out | std::ios::trunc);
//    std::String_t file = ttl::file2str("in");
//
//    std::cout << sizeof("derpader");
//
//
//    std::cout << file;
//    std::size_t position = file.find("#cxy");
//    if (position != file.npos)
//        file.insert(position, "int main(int argc, char *argv[])\n{\n\t\0");
//    output << file;
    File obj("in");
    obj.process();
    std::fstream o("out", std::ios::out | std::ios::trunc);
//    std::cout << obj;
    o << obj;
    std::cout << obj;

}

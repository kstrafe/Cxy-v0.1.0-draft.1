#include <TTL/TTL.hpp>
#include "File.hpp"
#include "Register.hpp"


int main(int argc, char *argv[])
{
    typedef std::size_t Sti_t;

    try
    {
        // Check if cxy has gotten any commands
        if (argc == 1)
        {
            std::cout
                << "Error: No input file(s) specified.\n"
                << "Enter \"cxy --help\" without quotation marks for help.";
            return 0;
        }

        // Parse all arguments
        ttl::Argument argument_store;
        argument_store.setInert('h'); argument_store.setInert("help");
        argument_store.setInert('c'); argument_store.setInert("compile");
        argument_store.setInert('e'); argument_store.setInert("execute");
        argument_store.setInert('i'); argument_store.setInert("interpret");
        argument_store.setInert('v'); argument_store.setInert("verbose");
        argument_store.setInert('u'); argument_store.setInert("unsafe");
        argument_store.setInert('s'); argument_store.setInert("safe");
        argument_store.pass(argc, argv);

        // Check if any invalid flags have been passed, unless the unsafe flag is passed.
        if (! (argument_store.isPassed('u') || argument_store.isPassed("unsafe")) )
        {
            std::string legal_flags[]
            {
                "h", "help",
                "c", "compile",
                "e", "execute",
                "i", "interpret",
                "r", "reflect",
                "v", "verbose",
                "u", "unsafe",
                "s", "safe",
                "o", "output"
            };

            auto iterator = argument_store.getFlagsAndParameters().begin();
            auto stop = argument_store.getFlagsAndParameters().end();

            for (; iterator != stop; ++iterator)
            {
                auto temporary = iterator->first;
                for (Sti_t i = 0; i < 2 && temporary.size() > 0 && temporary.front() == '-'; ++i)
                {
                    temporary.erase(temporary.begin());
                }


                decltype(&legal_flags[0]) position
                    =
                    std::find
                    (
                        legal_flags,
                        legal_flags + sizeof(legal_flags) / sizeof(decltype(legal_flags[0])),
                        temporary
                    );

                if (position == legal_flags + sizeof(legal_flags) / sizeof(decltype(legal_flags[0])))
                {
                    std::cout << "The flag \"" << iterator->first << "\" is not a valid flag. Aborting.\n";
                    return 0;
                }
            }
        }

        // Check if we need only to display a help menu.
        if (argument_store.isPassed('h') || argument_store.isPassed("help"))
        {
            std::cout
                << "\nCxy v0.1\n"
                << "Command line argument syntax:\n"
                << "[] means optional. <> means user-filled in. | means \"or\". \"...\" means a variadic amount of arguments.\n"
                << "() denotes evaluation order.\n"
                << "Any of the following can be combined together unless stated otherwise.\n"
                << "Example: \"cxy data.txt -u\"\n\n"
                << "cxy [-h | --help] - display this help info.\n"
                << "cxy <File1> <File2> ... - Run cxy on each file.\n"
                << "cxy [-u | --unsafe] - Turns off safety features (faster)\n"
                << "cxy [-c | --compile] - Compiles cxy files to cxy bytecode\n"
                << "cxy [-e | --execute] - Executes compiled cxy code, enabled -c\n"
                << "cxy [-i | --interpret] - Interprets cxy only. Does not mix with compile.\n"
                << "cxy [(-r | --reflect) <Folder>] - Will copy all processed files into the folder with the same path.\n\n";
            return 0;
        }

        // Add the working directory in front of every operand, considering every operand is a file to be worked on.
        {
            std::string working_directory = boost::filesystem::current_path().generic_string();
            working_directory.push_back('/');
            if (argument_store.isPassed('r') || argument_store.isPassed("reflect"))
            {

            }
            for (Sti_t i = 0; i < argument_store.getOperandCount(); ++i)
            {
                argument_store.getOperand(i) = working_directory + argument_store.getOperand(i);

                File obj(argument_store.getOperand(i), !(argument_store.isPassed('c') || argument_store.isPassed("compile")));
                try
                {
                    obj.read();
                    obj.include();
                    obj.parse();

                    if (argument_store.isPassed('c') || argument_store.isPassed("compile"))
                    {
                        obj.compile();
                    }
                    if (argument_store.isPassed('e') || argument_store.isPassed("execute"))
                    {
                        obj.execute();
                    }
                    else if (argument_store.isPassed('i') || argument_store.isPassed("interpret"))
                    {
                        obj.interpret();
                    }

                }
                catch (std::exception &exc_obj)
                {
                    std::cout
                        << "File error: "
                        << argument_store.getOperand(i)
                        << "\n> "
                        << exc_obj.what()
                        << "\n\n";
                }

                std::fstream o(argument_store.getOperand(i) + "_" , std::ios::out | std::ios::trunc);
            //    std::cout << obj;
                o << obj;
                std::cout << obj;
            }
        }
    }
    catch (std::exception &e)
    {
        std::cout << "An error occurred: " << e.what();
    }
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
}

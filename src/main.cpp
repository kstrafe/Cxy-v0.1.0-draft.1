#include <TTL/TTL.hpp>
#include "File.hpp"
#include "Register.hpp"

extern std::string get_absolute_path(std::string &, std::string &);
extern void remove_all_dot_slash_at_the_beginning(std::string &);
extern void get_non_dot_dot_path(std::string &);
extern std::string get_absolute_file(std::string &, std::string &);
extern std::string get_relative_to(const boost::filesystem::path path, const boost::filesystem::path base);


int main(int argc, char *argv[])
{
    typedef std::size_t Sti_t;

    // Makes sure to end the terminal in a nice newline.
    ttl::ScopedFunction sc([](){std::cout << '\n';});

    try
    {

        // Check if cxy has gotten any commands
        if (argc <= 1) // One argument reserved for program instantiation.
        {
            std::cout
                << "Error: No input argument(s) specified.\n"
                << "Enter \"cxy --help\" without quotation marks for help.";
            return 0;
        }

        // Parse the arguments
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
                    std::cout << "The flag \"" << iterator->first << "\" is not a valid flag. Aborting.";
                    return 0;
                }
            }
        }

        // Check if we need only to display a help menu.
        if (argument_store.isPassed('h') || argument_store.isPassed("help"))
        {
            std::cout
                << "Command line argument syntax:\n"
                << "[] means optional.\n<> means user-filled in.\n| means \"or\".\n\"...\" means a variadic amount of arguments.\n"
                << "() denotes evaluation order.\n\n"
                << "Any of the following can be combined together unless stated otherwise.\n"
                << "Example: \"cxy data.txt -u\"\n\n"
                << "cxy [-h | --help] - display this help info.\n"
                << "cxy <File1> <File2> ... - Run cxy on each file.\n"
                << "cxy [-u | --unsafe] - Turns off safety features (faster)\n"
                << "cxy [-c | --compile] - Compiles cxy files to cxy bytecode\n"
                << "cxy [-e | --execute] - Executes compiled cxy code, enabled -c\n"
                << "cxy [-i | --interpret] - Interprets cxy only. Does not mix with compile.\n"
                << "cxy [-o | --output] - Print output to the screen.\n"
                << "cxy [(-r | --reflect) <Folder>] - Will copy all processed files into the folder with the same path.";
            return 0;
        }

        std::string working_directory = boost::filesystem::current_path().generic_string();
        working_directory.push_back('/'); // Because it ends without a separator.

        // Remove all beginning ./, they're useless.
        for (Sti_t i = 0; i < argument_store.getOperandCount(); ++i)
        {
            remove_all_dot_slash_at_the_beginning(argument_store.getOperand(i));
            std::cout << "Operand: " << argument_store.getOperand(i) << std::endl;
        }
        std::cout << "\n";


        // Setting up a possible reflection system.
        {
            std::string reflection_directory;

            if (argument_store.isPassed('r') || argument_store.isPassed("reflect"))
            {
                boost::filesystem::path reflection_path;

                if (argument_store.isPassed('r'))
                    reflection_path = argument_store.getArgument('r');
                else if (argument_store.isPassed("reflect"))
                    reflection_path = argument_store.getArgument("reflect");

                if (reflection_path.is_relative())
                {
                    std::cout << "The path of reflection was relative!\n";
                    reflection_directory = working_directory + reflection_path.generic_string();
                    std::cout << "Reflection: " << reflection_directory << "\n\n";
                }
                else
                {
                    reflection_directory = reflection_path.generic_string();
                }

                if (reflection_directory.back() != '/')
                    reflection_directory.push_back('/');


                // Since the reflection is on, we need to replace absolutely-pathed operands:
                get_relative_to("C:/derp/qerp/merp destiny", "C:/derp/herp/merp, working dir.");
                for (Sti_t i = 0; i < argument_store.getOperandCount(); ++i)
                {
                    boost::filesystem::path path(argument_store.getOperand(i));
                    if (path.is_absolute())
                    {
                        argument_store.getOperand(i) = get_relative_to(path, working_directory);
                        std::cout << "The path is now: " << argument_store.getOperand(i) << std::endl;
                    }
                }

            }

            std::cout << "reflecting into: " << reflection_directory << std::endl;

            // Process each operand (file).
            // Add the working directory in front of every operand, considering every operand is a file to be worked on.
            for (Sti_t i = 0; i < argument_store.getOperandCount(); ++i)
            {
                // We fetch the absolute file to process...
                std::string absolute_file = get_absolute_file(working_directory, argument_store.getOperand(i));
                std::cout << "Absolute: " << absolute_file << std::endl;

                // We process this file...
                File obj(absolute_file, !(argument_store.isPassed('c') || argument_store.isPassed("compile")));
                try
                {
                    obj.read();
                    obj.include();
                    obj.parse();

                    if (argument_store.isPassed('c') || argument_store.isPassed("compile"))
                    {
                        obj.compile();
                        if (argument_store.isPassed('e') || argument_store.isPassed("execute"))
                        {
                            obj.execute();
                        }
                    }
                    else if (argument_store.isPassed('i') || argument_store.isPassed("interpret"))
                    {
                        obj.interpret();
                    }
                    std::string output_path = reflection_directory + argument_store.getOperand(i);

                    get_non_dot_dot_path(output_path);

                    // If a reflected folder does not exist, create one:
                    boost::filesystem::create_directories(boost::filesystem::path(output_path).parent_path());

                    std::cout << "Output into: " << output_path << std::endl;

                    std::fstream out(output_path, std::ios::out);
                    out << obj;

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

//                std::fstream o(argument_store.getOperand(i) + "_" , std::ios::out | std::ios::trunc);
//                o << obj;
//                std::cout << obj;
            }
        }
    }
    catch (std::exception &e)
    {
        std::cout << "An error occurred: " << e.what();
    }
}

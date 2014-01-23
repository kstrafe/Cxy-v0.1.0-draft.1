#include <TTL/TTL.hpp>
#include "File.hpp"
#include "Register.hpp"
#include <boost/integer.hpp>
#include "read_var.hpp"
#include "write_var.hpp"

extern std::string get_absolute_path(std::string &, std::string &);
extern void remove_all_dot_slash_at_the_beginning(std::string &);
extern void get_non_dot_dot_path(std::string &);
extern std::string get_absolute_file(std::string &, std::string &);
extern std::string get_relative_to(const boost::filesystem::path path, const boost::filesystem::path base);


class Verbose
{
public:

    Verbose() = default;
    void set(bool state){m_state = state;}
    template <typename T>
    Verbose &operator << (T t) {if (m_state) std::cout << t; return *this;}

private:

    bool m_state = false;
};

//template <typename T>
//class Condition
//{
//public:
//
//    Condition(T t){m_fn = t;}
//    void set(bool state){m_state = state;}
//    template <typename ...A>
//    Condition &operator () (A ...t) {if (m_state) m_fn(std::forward<A>(t)...); return *this;}
//    Condition &operator () () {if (m_state) m_fn(); return *this;}
//
//private:
//
//    T m_fn;
//    bool m_state = false;
//};


int main(int argc, char *argv[])
{
    typedef std::size_t Sti_t;

    // Makes sure to end the terminal in a nice newline.
    ttl::ScopedFunction sc([](){std::cout << '\n';});

    Verbose verbose, output;

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
        argument_store.setInert('b'); argument_store.setInert("bytecode");
        argument_store.pass(argc, argv);

        // Set the output state
        verbose.set(argument_store.isPassed('v') || argument_store.isPassed("verbose"));
        output.set(argument_store.isPassed('o') || argument_store.isPassed("output"));

        verbose << "Checking for unsafe flags (-u and --unsafe)\n";

        // Check if any invalid flags have been passed, unless the unsafe flag is passed.
        if (! (argument_store.isPassed('u') || argument_store.isPassed("unsafe")) )
        {

            verbose << "\tUnsafe flag not passed, checking all arguments.\n";

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
                "o", "output",
                "b", "bytecode"
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
            verbose << "\tNo invalid flags passed, continueing.\n";
        }
        else
        {
            verbose << "\tUnsafe flag passed, skipped argument validation.\n";
        }

        verbose << "Check if the help menu argument was passed\n";

        // Check if we need only to display a help menu.
        if (argument_store.isPassed('h') || argument_store.isPassed("help"))
        {
            verbose << "\tPrinting help menu\n";
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
                << "cxy [-i | --interpret] - Interprets cxy only. Does not mix with compile/execute.\n"
                << "cxy [-o | --output] - Print output file to the screen.\n"
                << "cxy [-s | --silent] - Do not execute \"show\" statements.\n"
                << "cxy [(-r | --reflect) <Folder>] - Will copy all processed files into the folder, preserving path structure.\n"
                << "cxy [-b | --bytecode] - Will preserve generated bytecode.";
            return 0;
        }

        verbose << "Fetching the working directory\n";

        std::string working_directory = boost::filesystem::current_path().generic_string();
        working_directory.push_back('/'); // Because it ends without a separator.

        verbose << "The working directory is: \"" << working_directory << "\"\nRemoving all operands that start with a ./\n";

        // Remove all beginning ./, they're useless.
        for (Sti_t i = 0; i < argument_store.getOperandCount(); ++i)
        {
            verbose << "Start Operand: " << argument_store.getOperand(i) << "\n";
            remove_all_dot_slash_at_the_beginning(argument_store.getOperand(i));
            verbose << "Finished Operand: " << argument_store.getOperand(i) << "\n";
        }
        verbose << "\n";


        // Setting up a possible reflection system.
        verbose << "Checking if the reflection argument (-r | --reflect) was passed.\n";
        {
            std::string reflection_directory;

            if (argument_store.isPassed('r') || argument_store.isPassed("reflect"))
            {
                verbose << "Reflection passed, setting up the reflection system\n";

                boost::filesystem::path reflection_path;

                if (argument_store.isPassed('r'))
                    reflection_path = argument_store.getArgument('r');
                else if (argument_store.isPassed("reflect"))
                    reflection_path = argument_store.getArgument("reflect");

                if (reflection_path.is_relative())
                {
                    verbose << "The path of reflection was relative!\n";
                    reflection_directory = working_directory + reflection_path.generic_string();
                }
                else
                {
                    verbose << "The path of reflection was not relative.\n";
                    reflection_directory = reflection_path.generic_string();
                }

                if (reflection_directory.back() != '/')
                    reflection_directory.push_back('/');


                verbose << "Reflection around: \"" << reflection_directory << "\"\n";

                // Since the reflection is on, we need to replace absolutely-pathed operands:
                verbose << "Replacing all absolutely-pathed operands provided.\n";
                for (Sti_t i = 0; i < argument_store.getOperandCount(); ++i)
                {
                    boost::filesystem::path path(argument_store.getOperand(i));
                    if (path.is_absolute())
                    {
                        verbose << "Original: " << argument_store.getOperand(i) << "\n";
                        argument_store.getOperand(i) = get_relative_to(path, working_directory);
                        verbose << "Replacement: " << argument_store.getOperand(i) << "\n";
                    }
                }

            }

            verbose << "Reflecting into: " << reflection_directory << "\n";

            // Process each operand (file).
            // Add the working directory in front of every operand, considering every operand is a file to be worked on.
            verbose << "Processing each file...\n";
            for (Sti_t i = 0; i < argument_store.getOperandCount(); ++i)
            {
                // We fetch the absolute file to process...
                std::string absolute_file = get_absolute_file(working_directory, argument_store.getOperand(i));
                verbose << "The file to process: " << absolute_file << "\n";

                // We process this file...
                File obj(absolute_file, !(argument_store.isPassed('c') || argument_store.isPassed("compile")));
                obj.setShow(!(argument_store.isPassed('s') || argument_store.isPassed("silent")));
                try
                {
                    verbose << "Reading the file into memory\n";
                    obj.read();
                    verbose << "Parsing all include statements\n";
                    obj.include();
                    verbose << "Parsing the data\n";
                    obj.parse();

                    verbose << "Checking for a compile (-c | --compile) flag.\n";
                    if (argument_store.isPassed('c') || argument_store.isPassed("compile"))
                    {
                        verbose << "Flag found, compiling\n";
                        obj.compile();
                    }
                    verbose << "Checking for an execute (-e | --execute) flag.\n";
                    if (argument_store.isPassed('e') || argument_store.isPassed("execute"))
                    {
                        verbose << "Execution flag found executing...\n";
                        obj.execute();
                    }
                    else if (argument_store.isPassed('i') || argument_store.isPassed("interpret"))
                    {
                        verbose << "Found interpret (-i | --interpret) flag instead...\n";
                        obj.interpret();
                    }
                    verbose << "Completed processing, preparing the output path\n";
                    std::string output_path = reflection_directory + argument_store.getOperand(i);
                    get_non_dot_dot_path(output_path);

                    // If a reflected folder does not exist, create one:
                    verbose << "Checking whether folder exists.\n";
                    if (!boost::filesystem::exists(boost::filesystem::path(output_path).parent_path()))
                    {
                        boost::filesystem::create_directories(boost::filesystem::path(output_path).parent_path());
                        verbose << "Folder did not exist, created\n";
                    }

                    verbose << "Output path: \"" << output_path << "\"\n";
                    std::fstream out(output_path, std::ios::out | std::ios::trunc | std::ios::binary);
                    out << obj;
                    verbose << "Data written.\n";

                    if (argument_store.isPassed('b') || argument_store.isPassed("bytecode"))
                    {
                        const std::vector<std::string> &instructions = obj.getInstructions();
                        if (instructions.size() > 0)
                        {
                            out.close();
                            out.open(output_path + ".bxy", std::ios::out | std::ios::trunc);
                            out << "#cxy starb\n";
                            // Create instruction table with # of bytes required:
                            for (Sti_t i = 0; i < instructions.size(); ++i)
                            {
                                write_var<Sti_t>(out, instructions[i].size());
                                std::cout << "Writing instruction\n: " << instructions[i] << std::endl;
                                out << instructions[i];
                            }
                            out << "\n#cxy stob";
                        }
                    }

                    output << obj << "\n";

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
            }
        }
    }
    catch (std::exception &e)
    {
        std::cout << "An error occurred: " << e.what();
    }
}

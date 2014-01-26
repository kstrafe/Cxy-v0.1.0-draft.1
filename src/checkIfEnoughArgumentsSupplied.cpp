// Headers
#include <>


void checkIfEnoughArgumentsSupplied(int number_of_args)
{
// Check if cxy has gotten any commands
    if (argc <= 1) // One argument reserved for program instantiation.
    {
        std::cout
            << "Error: No input argument(s) specified.\n"
            << "Enter \"cxy --help\" without quotation marks for help.";
        return 0;
    }
}

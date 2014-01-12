#ifndef FILE_HPP_INCLUDED
#define FILE_HPP_INCLUDED

// Headers
#include <TTL/TTL.hpp>
#include <iosfwd>


class File
{
public:

    File(const std::string &file);
    ~File() = default;

    void process(); // Executes read, include, parse, and interpret in that order.

    void read(); // Reads the entire file's contents into the buffer.
    void include(); // includes all #cxy <file> files.
    void parse(); // parse all #cxy statements.
    void interpret(); // Transform the statements into bytecode
    void execute(); // Execute all bytecode

    friend std::ostream &operator<<(std::ostream &os, const File &file);

private:

    typedef std::size_t sti;
    typedef std::map<std::string, std::vector<std::string>> Data_t;

    sti parseStatements(sti position);
    std::string getNextArgument(const std::string &str, sti &position);
    bool isValidStatementCharacter(char argument) const;

    // Statements
    // C
    void rep(sti &i); // remove marked sequence and replace
    // Can be written as:
    /* Let x be a string to be inserted

        ins x
        size x
        add pointer size
        add marker size
        del

    */

    // RISC string operations
    void ins(sti &i); // Insert character sequence at pointer 1 arg
    void del(sti &i); // delete behaviour 0 args
    void bck(sti &i); // backspace behaviour 0 args
    void cnt(sti &i); // count occurrence of string (1 arg) -> store result in "cnt"
    void find(sti &i); // Finds a string and marks it completely
    void size(sti &i); // Store the size of a string
    void capt(sti &i); // Capture the marked substr into a register.

    // CISC
    void show(sti &i); // Print a string (1 arg)
    void print(sti &i); // Print a string (1 arg)

    // RISC
    void if_statement(sti &i); // Check whether to execute or not (boolean arg)
    void goto_statement(sti &i); // Jump inside the code
    void eq(sti &i); // Check whether two registers are equal, store in "eq"
    void neq(sti &i); // Check whether two registers are equal, store in "eq"
    void lt(sti &i); // Check register1 > register2, store in "lt"
    void st(sti &i); // Check register1 < register2, store in "st"
    void inc(sti &i); // increase a register by 1
    void dec(sti &i); // Decrease a register by 1
    void add(sti &i); // Increment a register by another
    void sub(sti &i); // Decrement a register by another
    void push(sti &i); // Push a register
    void pop(sti &i); // Pop a register
    void mov(sti &i); // mov between registers
    void cp(sti &i); // copy a raw string into a register
    void next(sti &i); // Move the marker +1
    void prev(sti &i); // Move the cursor -1
    void and_statement(sti &i);
    void or_statement(sti &i);
    void xor_statement(sti &i);
    void not_statement(sti &i);

    void data(sti &i); // data accessor

    std::string                 m_file;
    std::string                 m_content;
    std::vector<std::string>    m_statements;
    Data_t                      m_data;
    const char                  m_parser_sign = '#';
    int
                                cursor = 0,
                                marker = 0;

};


#endif // FILE_HPP_INCLUDED

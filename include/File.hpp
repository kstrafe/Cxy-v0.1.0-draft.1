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

    // Useful shortening functions
    sti getNumber(const std::string &);
    std::string &getData(const std::string &);

    // Statements: All statements behave like text editor statements.

    // RISC string operations (these are complete.)
    void ins(sti &i); // Replace pointer-marker part with register content  (1) -> void
    void del(sti &i); // Delete button behaviour                            (0) -> void
    void bck(sti &i); // backspace behaviour                                (0) -> void
    void cnt(sti &i); // count occurrence of string                         (1) -> cnt
    void find(sti &i); // Finds a string and marks it completely            (1) -> ptr, mrk
    void size(sti &i); // Store the size of a string                        (1) -> size
    void capt(sti &i); // Capture the marked substr into a register.        (0) -> capt
    void trim(sti &i); // Remove non characters from the sides.             (1) -> [1]

    // CISC
    void show(sti &i); // Print a string to stdout                          (1) -> void

    // RISC, operations are considered complete and fully functional
    void if_statement(sti &i); // Check whether to execute or not           (1) -> void
    void goto_statement(sti &i); // Jump inside the code
    void eq(sti &i); // Check whether two registers are equal               (2) -> eq
    void neq(sti &i); // Opposite of eq                                     (2) -> neq
    void lt(sti &i); // Check register1 > register2, store in "lt"          (2) -> lt
    void st(sti &i); // Check register1 < register2, store in "st"          (2) -> st
    void inc(sti &i); // increase a register by 1                           (1) -> [1]
    void dec(sti &i); // Decrease a register by 1                           (1) -> [1]
    void add(sti &i); // Increment a register by another                    (2) -> [1]
    void sub(sti &i); // Decrement a register by another                    (2) -> [1]
    void push(sti &i); // Push a register                                   (1) -> [1]
    void pop(sti &i); // Pop a register                                     (1) -> [1]
    void mov(sti &i); // mov between registers                              (2) -> [1]
    void cp(sti &i); // copy the next statement into a register             (1*) -> [1]
    void next(sti &i); // Move the marker +1                                (0) -> mrk
    void prev(sti &i); // Move the cursor -1                                (0) -> ptr
    void and_statement(sti &i);
    void or_statement(sti &i);
    void xor_statement(sti &i);
    void not_statement(sti &i);

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

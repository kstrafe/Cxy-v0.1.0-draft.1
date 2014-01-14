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


    void process();     // Performs: read, include, parse, and interpret in that order.

    // Preparation stages:
    void read();        // Reads the entire file's contents into the buffer.
    void include();     // includes all #cxy <file> files.
    void parse();       // parse all #cxy statements.

    // Execution stages:
    void interpret();   // Interpret (and thereby execute) the mnemonics.
    // or
    void compile();     // Transform the statements into bytecode.
    void execute();     // Execute all bytecode, faster than interpreting mnemonics.

    friend std::ostream &operator<<(std::ostream &os, const File &file);

private:

    // Type definitions - allows an easy change of types.
    typedef std::size_t                                     Sti_t;          // Requirements: Largest possible index on the architecture of an array.
    typedef std::string                                     String_t;       // Requirements: std::string functions, character size >= instruction set size, convertible to Sti_t
    typedef std::map<String_t, std::vector<String_t>>       Data_t;         // Requirements: A switch from one String_t to a stack of String_t.
    typedef std::vector<String_t>                           Instructions_t; // Requirements: A random access iteratable collection of String_t.

    // Useful shortening functions.
    Sti_t getNumber(const String_t &); // Returns a number from a register
    String_t &getString(const String_t &); // Returns a string contained in a register
    const String_t &getString(const String_t &) const; // Returns a string contained in a register

    // Parsing functions.
    Sti_t parseStatements(Sti_t position); // Puts statements into m_instructions
    String_t getNextArgument(const String_t &str, Sti_t &position); // Parses out a single statement

    // Statements: All statements behave like text editor statements.

    // RISC String_t operations (these are complete.)
    void ins(Sti_t &i); // Replace pointer-marker part with register content  (1) -> void
    void del(Sti_t &i); // Delete button behaviour                            (0) -> void
    void bck(Sti_t &i); // backspace behaviour                                (0) -> void
    void cnt(Sti_t &i); // count occurrence of String_t                       (1) -> cnt
    void find(Sti_t &i); // Finds a String_t and marks it completely          (1) -> ptr, mrk
    void size(Sti_t &i); // Store the size of a String_t                      (1) -> size
    void capt(Sti_t &i); // Capture the marked substr into a register.        (0) -> capt
    void trim(Sti_t &i); // Remove non characters from the sides.             (1) -> [1]
    void cnc(Sti_t &i); // Concatenate 2 registers                            (2) -> [1]
    void drf(Sti_t &i); // Dereferencing operator                             (1) -> drf
    void rdf(Sti_t &i); // Reads an entire file into a register               (2) -> [1]

    // CISC
    void show(Sti_t &i); // Print a String_t to stdout                        (1) -> void

    // RISC, operations are considered complete and fully functional
    void if_statement(Sti_t &i); // Check whether to execute or not           (1) -> void
    void goto_statement(Sti_t &i); // Jump inside the code
    void eq(Sti_t &i); // Check whether two registers are equal               (2) -> eq
    void neq(Sti_t &i); // Opposite of eq                                     (2) -> neq
    void lt(Sti_t &i); // Check register1 > register2, store in "lt"          (2) -> lt
    void st(Sti_t &i); // Check register1 < register2, store in "st"          (2) -> st
    void inc(Sti_t &i); // increase a register by 1                           (1) -> [1]
    void dec(Sti_t &i); // Decrease a register by 1                           (1) -> [1]
    void add(Sti_t &i); // Increment a register by another                    (2) -> [1]
    void sub(Sti_t &i); // Decrement a register by another                    (2) -> [1]
    void push(Sti_t &i); // Push a register                                   (1) -> [1]
    void pop(Sti_t &i); // Pop a register                                     (1) -> [1]
    void mov(Sti_t &i); // mov between registers                              (2) -> [1]
    void cpy(Sti_t &i); // copy the next statement into a register            (1*) -> [1]
    void next(Sti_t &i); // Move the marker +1                                (0) -> mrk
    void prev(Sti_t &i); // Move the cursor -1                                (0) -> ptr
    void and_statement(Sti_t &i);
    void or_statement(Sti_t &i);
    void xor_statement(Sti_t &i);
    void not_statement(Sti_t &i);

    std::string                 m_file;
    Instructions_t              m_instructions;
    Data_t                      m_data;
    const char                  m_parser_sign = '#';

    // Ordering does not matter
    enum class Instruction
    {
        add,
        and_statement,
        bck,
        capt,
        cnc,
        cnt,
        cpy,
        dec,
        del,
        drf,
        eq,
        find,
        goto_statement,
        if_statement,
        inc,
        ins,
        lt,
        mov,
        neq,
        next,
        not_statement,
        or_statement,
        pop,
        prev,
        push,
        rdf,
        show,
        size,
        st,
        sub,
        trim,
        xor_statement
    };

};


#endif // FILE_HPP_INCLUDED

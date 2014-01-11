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
    void interpret(); // Interprets all stored individual cxy statements.

    friend std::ostream &operator<<(std::ostream &os, const File &file);

private:

    typedef std::size_t sti;
    typedef std::map<std::string, std::string> Data_t;

    sti parseStatements(sti position);
    std::string getNextArgument(const std::string &str, sti &position);
    bool isInvalidStatementCharacter(char argument) const;

    // Statements
    void rep(sti &i); // replace string by string (2 args)
    void cnt(sti &i); // count occurrence of string (1 arg)
    void show(sti &i); // Print a string (1 arg)
    void print(sti &i); // Print a string (1 arg)
    void if_statement(sti &i); // Check whether to execute or not (1,... n args)
    void goto_statement(sti &i); // Print a string (1 arg)
    void lt(sti &i); // Check whether to execute or not (1,... n args)
    void st(sti &i); // Print a string (1 arg)
    void inc(sti &i); // Print a string (1 arg)

    void data(sti &i); // data accessor

    std::string                 m_file;
    std::string                 m_content;
    std::vector<std::string>    m_statements;
    Data_t                      m_data;
    const char                  m_parser_sign = '#';

};


#endif // FILE_HPP_INCLUDED

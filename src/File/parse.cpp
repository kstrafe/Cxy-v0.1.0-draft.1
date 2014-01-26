// Headers
#include "File.hpp"
#include <boost/tokenizer.hpp>
#include "read_var.hpp"
#include <TTL/TTL.hpp>

#define sout(X) (std::cout << X << "\n");
extern std::string get_first_most_nested_cxy_data(const std::string &content);
extern std::string get_second_most_nested_data(const std::string &content);
extern std::string erase_all_cxy_statements(const std::string &content);
extern void erase_first_most_nested_cxy_data(std::string &content);
extern void replace_second_most_nested_scope(std::string &content, std::string &with);


/*
    Parse all the #cxy statements from the file.
    Binary nestings must run before the previous nest.
*/
void File::parse()
{
    static constexpr const Sti_t REMAINING_LAST = 1, DELIMITING_CHAR = 1, END_OF_EXPRESSION = 8;

    std::string content = getString(m_id[Sti_t(Runstate::Execute)][Sti_t(Symbol::cntnt)]);
    try
    {
        while (content.find("#cxy star") != std::string::npos)
        {
            sout("CONTENT: ")
            sout(content)

            std::string instructions = get_first_most_nested_cxy_data(content);
            sout("Instructions queried:")
            sout(instructions)

            std::string operating_data = erase_all_cxy_statements(get_second_most_nested_data(content));
            sout("Operating data:")
            sout(operating_data)

            reinstruct(instructions);
            m_data[m_id[Sti_t(Runstate::Execute)][Sti_t(Symbol::cntnt)]].push_back(operating_data); // Turn "cntnt" into the name... goto sleep

            compile();
            execute();

            std::string generated_content = m_data[m_id[Sti_t(Runstate::Execute)][Sti_t(Symbol::cntnt)]].back();
            m_data[m_id[Sti_t(Runstate::Execute)][Sti_t(Symbol::cntnt)]].pop_back();

//            sout("Generated content2")
//            sout(generated_content)


//            sout("Old content")
//            sout(content)

            replace_second_most_nested_scope(content, generated_content);

//            std::cout << "Final: " << content << "===================================\n\n";

            erase_first_most_nested_cxy_data(content);

//            std::cout << "Final2: " << content << "===================================\n\n";
        }

        m_data[m_id[Sti_t(Runstate::Execute)][Sti_t(Symbol::cntnt)]].back() = content;


    }
    catch (std::exception &e)
    {
        std::cout << "Error occurred during parsing: " << e.what() << std::endl;
        throw;
    }
}


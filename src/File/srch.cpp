// Headers
#include "File.hpp"
#include <boost/regex.hpp>


/*
    Contrast to find, searches content from ptr to mrk for a
    regular expression. Returns the results in ptr and mrk.
*/
void File::srch(Sti_t &i)
{
    std::string &content(getString(Symbol::cntnt));
    Sti_t
        ptr = getNumber(Symbol::ptr),
        mrk = getNumber(Symbol::mrk);

    std::string::const_iterator begin, end;

    begin = content.begin() + ptr;
    end = (ptr == mrk ? content.end() : content.begin() + mrk);

    boost::regex regular_expression(getString(m_instructions[i + 1]));
    boost::match_results<std::string::const_iterator> match;
    boost::match_flag_type flags = boost::match_default;

    if (boost::regex_search(begin, end, match, regular_expression, flags))
    {
        for (Sti_t i = match.size() - 1;; --i)
        {
            begin = match[i].first;
            end = match[i].second;
            m_data[reg2str(Symbol::ptr)].emplace_back(std::distance(content.cbegin(), begin));
            m_data[reg2str(Symbol::mrk)].emplace_back(std::distance(content.cbegin(), end));

            if (i == 0)
                break;
        }
    }

    i += 1;
}

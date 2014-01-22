// Headers
#include  "File.hpp"


void File::reset(Sti_t &i) // Unstable...
{
    // TODO: Clear everything completely, except for m_instructions and m_data["cntnt"] and m_file.
//    Register_t tmp = getRegister("cntnt");
    for (decltype(m_data)::iterator it = m_data.begin(); it != m_data.end(); ++it)
    {
        if (it->first != "cntnt")
        {
            it->second.clear();
        }
    }
//    m_data.erase
//    (
//        std::remove_if
//        (
//            m_data.begin(), m_data.end(),
//            [](std::pair<String_t, std::vector<Register_t>> &r) -> bool
//            {
//                return r.first != "cntnt";
//            }
//        ),
//        m_data.end()
//    );
//
//    m_data["cnt"].emplace_back(0);
//    m_data["eq"].emplace_back(0);
//    m_data["neq"].emplace_back(0);
//    m_data["lt"].emplace_back(0);
//    m_data["st"].emplace_back(0);
//    m_data["ptr"].emplace_back(0);
//    m_data["mrk"].emplace_back(0);
//    m_data["size"].emplace_back(0);
//    m_data["next"].emplace_back("");
//    m_data["prev"].emplace_back("");
//    m_data["and"].emplace_back(0);
//    m_data["or"].emplace_back(0);
//    m_data["xor"].emplace_back(0);
//    m_data["not"].emplace_back(0);
//    m_data["capt"].emplace_back("");
//    m_data["drf"].emplace_back("");
//
//    m_data["cnt"].emplace_back(0);
//    m_data["eq"].emplace_back(0);
//    m_data["neq"].emplace_back(0);
//    m_data["lt"].emplace_back(0);
//    m_data["st"].emplace_back(0);
//    m_data["ptr"].emplace_back(0);
//    m_data["mrk"].emplace_back(0);
//    m_data["size"].emplace_back(0);
//    m_data["next"].emplace_back("");
//    m_data["prev"].emplace_back("");
//    m_data["and"].emplace_back(0);
//    m_data["or"].emplace_back(0);
//    m_data["xor"].emplace_back(0);
//    m_data["not"].emplace_back(0);
//    m_data["capt"].emplace_back("");
//    m_data["drf"].emplace_back("");

//    m_data["cntnt"].emplace_back(tmp);
}

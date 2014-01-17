#include  "File.hpp"
#include  <iostream>
#include  <stdexcept>


File::File(const std::string &file)
:
    m_file(file)
{
    m_data["cnt"].emplace_back("0");
    m_data["eq"].emplace_back("0");
    m_data["neq"].emplace_back("0");
    m_data["lt"].emplace_back("0");
    m_data["st"].emplace_back("0");
    m_data["ptr"].emplace_back("0");
    m_data["mrk"].emplace_back("0");
    m_data["size"].emplace_back("0");
    m_data["next"].emplace_back("");
    m_data["prev"].emplace_back("");
    m_data["and"].emplace_back("0");
    m_data["or"].emplace_back("0");
    m_data["xor"].emplace_back("0");
    m_data["not"].emplace_back("0");
    m_data["capt"].emplace_back("");
    m_data["drf"].emplace_back(" ");
    m_data["cntnt"].emplace_back("");
    m_data["odir"].emplace_back("");
    m_data["isdr"].emplace_back("0");
    m_data["extp"].emplace_back("");
    m_data["fln"].emplace_back("");
}

// Headers
#include "File.hpp"


void File::read()
{
    getRegister(m_id[Sti_t(Runstate::Execute)][Sti_t(Symbol::cntnt)]) = ttl::file2str(m_file);
    if (m_data.find(m_id[Sti_t(Runstate::Execute)][Sti_t(Symbol::cntnt)]) == m_data.end())
        throw std::invalid_argument("The content register has not yet been pushed.");
}

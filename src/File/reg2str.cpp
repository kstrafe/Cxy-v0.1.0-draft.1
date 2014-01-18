// Headers
#include "File.hpp"


auto File::reg2str(const Symbol s) const -> const String_t &
{
    return m_id[static_cast<Sti_t>(m_runstate)][static_cast<Sti_t>(s)];
}

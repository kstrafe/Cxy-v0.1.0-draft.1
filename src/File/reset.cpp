// Headers
#include  "File.hpp"


void File::reset(Sti_t &i)
{
    m_data[reg2str(Symbol::cnt)].resize(1);
    m_data[reg2str(Symbol::cnt)].resize(1);
    m_data[reg2str(Symbol::eq)].resize(1);
    m_data[reg2str(Symbol::neq)].resize(1);
    m_data[reg2str(Symbol::lt)].resize(1);
    m_data[reg2str(Symbol::st)].resize(1);
    m_data[reg2str(Symbol::ptr)].resize(1);
    m_data[reg2str(Symbol::mrk)].resize(1);
    m_data[reg2str(Symbol::size)].resize(1);
    m_data[reg2str(Symbol::next)].resize(1);
    m_data[reg2str(Symbol::prev)].resize(1);
    m_data[reg2str(Symbol::and_statement)].resize(1);
    m_data[reg2str(Symbol::or_statement)].resize(1);
    m_data[reg2str(Symbol::xor_statement)].resize(1);
    m_data[reg2str(Symbol::not_statement)].resize(1);
    m_data[reg2str(Symbol::capt)].resize(1);
    m_data[reg2str(Symbol::drf)].resize(1);
    m_data[reg2str(Symbol::cntnt)].resize(1);
    m_data[reg2str(Symbol::odir)].resize(1);
    m_data[reg2str(Symbol::isdr)].resize(1);
    m_data[reg2str(Symbol::extp)].resize(1);
    m_data[reg2str(Symbol::fln)].resize(1);
    m_data[reg2str(Symbol::match)].resize(1);
    m_data[reg2str(Symbol::get)].resize(1);
    m_data[reg2str(Symbol::set)].resize(1);
    m_data[reg2str(Symbol::hght)].resize(1);

//    getRegister(Symbol::cnt) = 0;
//    getRegister(Symbol::eq) = 0;
//    getRegister(Symbol::neq) = 0;
//    getRegister(Symbol::lt) = 0;
//    getRegister(Symbol::st) = 0;
    getRegister(Symbol::ptr) = 0;
    getRegister(Symbol::mrk) = 0;
//    getRegister(Symbol::size) = 0;
    getRegister(Symbol::next) = 0;
    getRegister(Symbol::prev) = 0;
//    getRegister(Symbol::and_statement) = 0;
//    getRegister(Symbol::or_statement) = 0;
//    getRegister(Symbol::xor_statement) = 0;
//    getRegister(Symbol::not_statement) = 0;
//    getRegister(Symbol::capt) = "";
//    getRegister(Symbol::drf) = " ";
//    getRegister(Symbol::cntnt) = 0;
//    getRegister(Symbol::odir) = "";
//    getRegister(Symbol::isdr) = 0;
//    getRegister(Symbol::extp) = 0;
//    getRegister(Symbol::fln) = 0;
//    getRegister(Symbol::match) = 0;
//    getRegister(Symbol::get) = 0;
//    getRegister(Symbol::set) = 0;
//    getRegister(Symbol::hght) = 0;

}


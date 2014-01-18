// Headers
#include "File.hpp"


void File::execute()
{
    m_runstate = Runstate::Execute;
//    for (Sti_t i = 0; i < static_cast<Sti_t>(Symbol::END_REGISTER_SYMBOLS); ++i)
//    {
//        std::string tmp;
//        tmp.push_back(static_cast<char>(static_cast<Symbol_enum_t>(i)));
//        m_data[tmp].emplace_back(0);
//    }

    for (Sti_t i = 0; i < m_instructions.size(); ++i)
    {
//        std::cout << "try deref...\n";
        String_t &str = m_instructions[i];
//        std::cout << "deref...\n";
//        std::cout << "Executing: " << str << "\n";
        switch (static_cast<Symbol>(str[0]))
        {
            case Symbol::ins: ins(i); break;
            case Symbol::del: del(i); break;
            case Symbol::bck: bck(i); break;
            case Symbol::cnt: cnt(i); break;
            case Symbol::find: find(i); break;
            case Symbol::size: size(i); break;
            case Symbol::capt: capt(i); break;
            case Symbol::trim: trim(i); break;
            case Symbol::cnc: cnc(i); break;
            case Symbol::drf: drf(i); break;
            case Symbol::rdf: rdf(i); break;
            case Symbol::swap: swap(i); break;
            case Symbol::dir: dir(i); break;
            case Symbol::odir: odir(i); break;
            case Symbol::isdr: isdr(i); break;
            case Symbol::extp: extp(i); break;
            case Symbol::updr: updr(i); break;
            case Symbol::fln: fln(i); break;
            case Symbol::adir: adir(i); break;
            case Symbol::show: show(i); break;
            case Symbol::reset: reset(i); break;
            case Symbol::if_statement: if_statement_c(i); break;
            case Symbol::goto_statement: goto_statement_c(i); break;
            case Symbol::eq: eq(i); break;
            case Symbol::neq: neq(i); break;
            case Symbol::lt: lt(i); break;
            case Symbol::st: st(i); break;
            case Symbol::inc: inc(i); break;
            case Symbol::dec: dec(i); break;
            case Symbol::add: add(i); break;
            case Symbol::sub: sub(i); break;
            case Symbol::push: push(i); break;
            case Symbol::pop: pop(i); break;
            case Symbol::mov: mov(i); break;
            case Symbol::cpy: cpy(i); break;
            case Symbol::next: next(i); break;
            case Symbol::prev: prev(i); break;
            case Symbol::and_statement: and_statement(i); break;
            case Symbol::or_statement: or_statement(i); break;
            case Symbol::xor_statement: xor_statement(i); break;
            case Symbol::not_statement: not_statement(i); break;
            default: std::cout << "Error\n";
        }
//        std::cout << "Statement finished...\n";
    }

//    std::cout << "Exited loop\n";

//    m_instructions.clear();
}

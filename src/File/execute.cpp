// Headers
#include "File.hpp"


void File::execute()
{
    for (Sti_t i = 0; i < static_cast<Sti_t>(Instruction::END); ++i)
    {
        std::string tmp;
        tmp.push_back(static_cast<char>(static_cast<Instruction>(i)));
        m_data[tmp].emplace_back(0);
    }

    for (Sti_t i = 0; i < m_instructions.size(); ++i)
    {
        String_t &str = m_instructions[i];
        Instruction s = static_cast<Instruction>(str[0]);
        switch (s)
        {
            case Instruction::ins: ins(i); break;
            case Instruction::del: del(i); break;
            case Instruction::bck: bck(i); break;
            case Instruction::cnt: cnt(i); break;
            case Instruction::find: find(i); break;
            case Instruction::size: size(i); break;
            case Instruction::capt: capt(i); break;
            case Instruction::trim: trim(i); break;
            case Instruction::cnc: cnc(i); break;
            case Instruction::drf: drf(i); break;
            case Instruction::rdf: rdf(i); break;
            case Instruction::swap: swap(i); break;
            case Instruction::dir: dir(i); break;
            case Instruction::odir: odir(i); break;
            case Instruction::isdr: isdr(i); break;
            case Instruction::extp: extp(i); break;
            case Instruction::updr: updr(i); break;
            case Instruction::fln: fln(i); break;
            case Instruction::adir: adir(i); break;
            case Instruction::show: show(i); break;
            case Instruction::reset: reset(i); break;
            case Instruction::if_statement: if_statement_c(i); break;
            case Instruction::goto_statement: goto_statement_c(i); break;
            case Instruction::eq: eq_c(i); break;
            case Instruction::neq: neq(i); break;
            case Instruction::lt: lt(i); break;
            case Instruction::st: st(i); break;
            case Instruction::inc: inc(i); break;
            case Instruction::dec: dec(i); break;
            case Instruction::add: add(i); break;
            case Instruction::sub: sub(i); break;
            case Instruction::push: push(i); break;
            case Instruction::pop: pop(i); break;
            case Instruction::mov: mov(i); break;
            case Instruction::cpy: cpy(i); break;
            case Instruction::next: next(i); break;
            case Instruction::prev: prev(i); break;
            case Instruction::and_statement: and_statement(i); break;
            case Instruction::or_statement: or_statement(i); break;
            case Instruction::xor_statement: xor_statement(i); break;
            case Instruction::not_statement: not_statement_c(i); break;
            default: std::cout << "Error\n";
        }
    }

    m_instructions.clear();
}

// Headers
#include "File.hpp"


void File::execute()
{
    std::remove_reference<decltype(m_instructions[0][0])>::type
        symbol;
    for (Sti_t i = 0; i < m_instructions.size(); ++i)
    {
//        std::cout << "Next instr: " << i << " vs " << m_instructions.size() << std::endl;
        symbol = m_instructions.at(i).at(0);
        switch (static_cast<Symbol>(symbol))
        {
//            case Symbol::ins: std::cout << "ins(i);" << '\n'; ins(i);                               break;
//            case Symbol::del: std::cout << "del(i);" << '\n'; del(i);                               break;
//            case Symbol::bck: std::cout << "bck(i);" << '\n'; bck(i);                               break;
//            case Symbol::cnt: std::cout << "cnt(i);" << '\n'; cnt(i);                               break;
//            case Symbol::find: std::cout << "find(i);" << '\n'; find(i);                             break;
//            case Symbol::size: std::cout << "size(i);" << '\n'; size(i);                             break;
//            case Symbol::capt: std::cout << "capt(i);" << '\n'; capt(i);                             break;
//            case Symbol::trim: std::cout << "trim(i);" << '\n'; trim(i);                             break;
//            case Symbol::cnc: std::cout << "cnc(i);" << '\n'; cnc(i);                               break;
//            case Symbol::drf: std::cout << "drf(i);" << '\n'; drf(i);                               break;
//            case Symbol::rdf: std::cout << "rdf(i);" << '\n'; rdf(i);                               break;
//            case Symbol::swap: std::cout << "swap(i);" << '\n'; swap(i);                             break;
//            case Symbol::dir: std::cout << "dir(i);" << '\n'; dir(i);                               break;
//            case Symbol::odir: std::cout << "odir(i);" << '\n'; odir(i);                             break;
//            case Symbol::isdr: std::cout << "isdr(i);" << '\n'; isdr(i);                             break;
//            case Symbol::extp: std::cout << "extp(i);" << '\n'; extp(i);                             break;
//            case Symbol::updr: std::cout << "updr(i);" << '\n'; updr(i);                             break;
//            case Symbol::fln: std::cout << "fln(i);" << '\n'; fln(i);                               break;
//            case Symbol::adir: std::cout << "adir(i);" << '\n'; adir(i);                             break;
//            case Symbol::show: std::cout << "show(i);" << '\n'; show(i);                             break;
//            case Symbol::reset: std::cout << "reset(i);" << '\n'; reset(i);                           break;
//            case Symbol::if_statement: std::cout << "if_statement_c(i);" << '\n'; if_statement_c(i);           break;
//            case Symbol::goto_statement: std::cout << "goto_statement_c(i);" << '\n'; goto_statement_c(i);       break;
//            case Symbol::eq: std::cout << "eq(i);" << '\n'; eq(i);                                 break;
//            case Symbol::neq: std::cout << "neq(i);" << '\n'; neq(i);                           break;
//            case Symbol::lt: std::cout << "lt(i);" << '\n'; lt(i); break;
//            case Symbol::st: std::cout << "st(i);" << '\n'; st(i); break;
//            case Symbol::inc: std::cout << "inc(i);" << '\n'; inc(i); break;
//            case Symbol::dec: std::cout << "dec(i);" << '\n'; dec(i); break;
//            case Symbol::add: std::cout << "add(i);" << '\n'; add(i); break;
//            case Symbol::sub: std::cout << "sub(i);" << '\n'; sub(i); break;
//            case Symbol::push: std::cout << "push(i);" << '\n'; push(i); break;
//            case Symbol::pop: std::cout << "pop(i);" << '\n'; pop(i); break;
//            case Symbol::mov: std::cout << "mov(i);" << '\n'; mov(i); break;
//            case Symbol::cpy: std::cout << "cpy(i);" << '\n'; cpy(i); break;
//            case Symbol::next: std::cout << "next(i);" << '\n'; next(i); break;
//            case Symbol::prev: std::cout << "prev(i);" << '\n'; prev(i); break;
//            case Symbol::and_statement: std::cout << "and_statement(i);" << '\n'; and_statement(i); break;
//            case Symbol::or_statement: std::cout << "or_statement(i);" << '\n'; or_statement(i); break;
//            case Symbol::xor_statement: std::cout << "xor_statement(i);" << '\n'; xor_statement(i); break;
//            case Symbol::not_statement: std::cout << "not_statement(i);" << '\n'; not_statement(i); break;

            case Symbol::ins:   ins(i); break;
            case Symbol::del:   del(i); break;
            case Symbol::bck:   bck(i); break;
            case Symbol::cnt:   cnt(i); break;
            case Symbol::find:  find(i); break;
            case Symbol::rfind:  rfind(i); break;
            case Symbol::size:  size(i); break;
            case Symbol::capt:  capt(i); break;
            case Symbol::trim:  trim(i); break;
            case Symbol::cnc:   cnc(i); break;
            case Symbol::drf:   drf(i); break;
            case Symbol::rdf:   rdf(i); break;
            case Symbol::swap:  swap(i); break;
            case Symbol::repl:  repl(i); break;
            case Symbol::match:  match(i); break;
            case Symbol::srch:  srch(i); break;
            case Symbol::hght:  hght(i); break;
            case Symbol::dir:   dir(i); break;
            case Symbol::odir:  odir(i); break;
            case Symbol::isdr:  isdr(i); break;
            case Symbol::extp:  extp(i); break;
            case Symbol::updr:  updr(i); break;
            case Symbol::fln:   fln(i); break;
            case Symbol::adir:  adir(i); break;
            case Symbol::show:  show(i); break;
            case Symbol::reset: reset(i); break;
            case Symbol::if_statement: if_statement_c(i); break;
            case Symbol::goto_statement: goto_statement_c(i); break;
            case Symbol::eq:    eq(i); break;
            case Symbol::neq:   neq(i); break;
            case Symbol::lt:    lt(i); break;
            case Symbol::st:    st(i); break;
            case Symbol::inc:   inc(i); break;
            case Symbol::dec:   dec(i); break;
            case Symbol::add:   add(i); break;
            case Symbol::sub:   sub(i); break;
            case Symbol::push:  push(i); break;
            case Symbol::pop:   pop(i); break;
            case Symbol::mov:   mov(i); break;
            case Symbol::cpy:   cpy(i); break;
            case Symbol::next:  next(i); break;
            case Symbol::prev:  prev(i); break;
            case Symbol::and_statement: and_statement(i); break;
            case Symbol::or_statement: or_statement(i); break;
            case Symbol::xor_statement: xor_statement(i); break;
            case Symbol::not_statement: not_statement(i); break;
            case Symbol::get: get(i); break;
            case Symbol::set: set(i); break;


            default: std::cout << "OPCODE\n"; throw std::runtime_error
                     (
                        "Invalid Opcode detected (id = "
                        + std::to_string(Sti_t(symbol))
                        + ")"
                     );
        }
    }
}

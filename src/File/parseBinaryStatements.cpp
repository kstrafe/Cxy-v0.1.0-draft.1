// Headers
#include "File.hpp"
#include "read_var.hpp"


auto File::parseBinaryStatements(Sti_t position) -> Sti_t
{
    std::cout << "String whilst reading: " << getString("cntnt") << std::endl;
    std::string tof("#cxy stob");
    Sti_t end = getString("cntnt").find(tof);

//    ttl::ScopedFunction end_add([&end](){);});

    std::istringstream iss(getString("cntnt").substr(position, end - position));
    end += (sizeof("#cxy stob") / sizeof(char) - 1);
    std::cout << "\n\n";
    std::cout << iss.str() << std::endl;
    std::cout << "\n\n";
    while (iss.good())
    {
        Sti_t n = read_var<Sti_t>(iss);
        if (n == 0)
            break;

//        std::cout << "We read: " << n << std::endl;
        char refch;
        std::string instruction;
        for (Sti_t i = 0; i < n; ++i)
        {
            std::cout << i;
            iss.get(refch);
            if (iss.eof())
                return end;
            instruction.push_back(refch);
        }
        m_instructions.push_back(std::move(instruction));
    }
    return end;
}

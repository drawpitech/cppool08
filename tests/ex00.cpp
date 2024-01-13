#include <iostream>

#include "../ex00/Droid.hpp"

int main() {
    Droid d;
    Droid d1("Avenger");
    size_t Durasel = 200;

    std::cout << d << '\n';
    std::cout << d1 << '\n';
    d = d1;
    d.setStatus(new std::string("Kill Kill Kill!"));
    d << Durasel;
    std::cout << d << "--" << Durasel << '\n';
    Droid d2 = d;
    d.setId("Rex");
    std::cout << (d2 != d) << '\n';
}

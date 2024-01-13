#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include <iostream>

#include "../ex00/Droid.hpp"

Test(ex00, subject_example, .init = cr_redirect_stdout) {
    do {
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
    } while (false);

    std::cout << std::flush;
    cr_assert_stdout_eq_str(
        /* std::cout << ( */
        "Droid '' Activated\n"
        "Droid 'Avenger' Activated\n"
        "Droid '', Standing by, 50\n"
        "Droid 'Avenger', Standing by, 50\n"
        "Droid 'Avenger', Kill Kill Kill!, 100--150\n"
        "Droid 'Avenger' Activated, Memory Dumped\n"
        "1\n"
        "Droid 'Avenger' Destroyed\n"
        "Droid 'Avenger' Destroyed\n"
        "Droid 'Rex' Destroyed\n");
}

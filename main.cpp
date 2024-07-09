#include <iostream>
#include "respo.h"

int main([[maybe_unused]] int argc, [[maybe_unused]] char const* argv[]) {
    std::vector<unsigned long long> s{9, 10, 7};

    std::cout << respo::min_value(s) << std::endl;

    return 0;
}
#include <iostream>

unsigned square_chain(unsigned n) {
    unsigned res{0u};
    while (n > 0) {
        res += ((n % 10u) * (n % 10u));
        n /= 10u;
    }
    return res;
}

int main([[maybe_unused]] int argc, [[maybe_unused]] char const *argv[]) {
    size_t counter{0u};
    for (unsigned i{2u}; i < 10'000'000u; i++) {
        unsigned n{i};
        while ((n != 1) && (n != 89)) {
            n = square_chain(n);
        }
        if (n == 89) ++counter;
    }

    std::cout << counter << std::endl;

    return 0;
}
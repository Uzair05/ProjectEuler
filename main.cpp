#include <iostream>

template <typename T>
T sqr(T n) {
    return n * n;
}

int main([[maybe_unused]] int argc, [[maybe_unused]] char const *argv[]) {
    for (unsigned i{100}; i < 498; i++) {
        for (auto j{i + 1}; j < 499; j++) {
            for (auto k{j + 1}; k < 500; k++) {
                if ((sqr(i) + sqr(j)) == sqr(k)) {
                    if ((i + j + k) == 1000) {
                        std::cout << i * j * k << "\r\n";
                    }
                }
            }
        }
    }

    return 0;
}
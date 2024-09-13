#include <iostream>
#include <type_traits>

template <typename T>
inline bool is_palindrome(T n) {
    static_assert(std::is_integral<T>::value);
    T n_1{0};
    T n_2{n};
    while (n > 0) {
        n_1 *= 10;
        n_1 += n % 10;
        n /= 10;
    }
    return (n_1 == n_2);
}

bool is_lychrel(unsigned long long n, size_t depth = 0ul) {
    if (depth > 49) return false;
    if (depth > 0) {
        if (is_palindrome<unsigned long long>(n)) return true;
    }

    auto n_{0ull};
    auto n__{n};
    while (n > 0) {
        n_ *= 10ull;
        n_ += n % 10ull;
        n /= 10ull;
    }

    return is_lychrel(n__ + n_, depth + 1);
}

int main([[maybe_unused]] int argc, [[maybe_unused]] char const *argv[]) {
    size_t counter{0ul};
    for (size_t i{0ul}; i < 10'000ul; i++) {
        if (!is_lychrel(i)) ++counter;
    }

    std::cout << counter << std::endl;
    return 0;
}
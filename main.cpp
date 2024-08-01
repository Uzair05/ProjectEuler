#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

template <typename T>
void build_primes(std::vector<T>& primes, T n) {
    if (primes.empty()) primes.push_back(2);

    bool flg;
    for (auto i{primes.back() + 1}; i < n; i++) {
        flg = false;
        for (const auto& p : primes) {
            if (i % p == 0) {
                flg = true;
                break;
            }
        }

        if (!flg) {
            primes.push_back(i);
        }
    }
}

int main([[maybe_unused]] int argc, [[maybe_unused]] char const* argv[]) {
    std::vector<unsigned long long> primes{};

    build_primes(primes, 1'000'000ull);
    const auto last_prime{primes.back()};

    bool break_flg{false};
    for (int window_size{static_cast<int>(primes.size() - 1)}; window_size > 20; window_size--) {
        for (auto it{primes.begin()}; it != (primes.end() - window_size); it++) {
            auto acc = std::accumulate(it, it + window_size, 0ull);
            if (acc > last_prime) break;

            if (std::binary_search(primes.begin(), primes.end(), acc)) {
                std::cout << "For Prime: " << acc << "\n";
                std::for_each(it, it + window_size, [](const auto& n) { std::cout << n << ", "; });
                std::cout << "\n";
                break_flg = true;
                break;
            }
        }

        if (break_flg) break;
    }

    return 0;
}
#include <algorithm>
#include <iostream>
#include <numeric>
#include <set>
#include <vector>

template <typename T>
void build_primes(std::vector<T>& primes, T n) {
    if (primes.size() < 2) {
        if (primes.empty()) {
            primes.push_back(2);
        }
        primes.push_back(3);
    }

    bool flg;
    for (auto i{primes.back() + 2}; i < n; i += 2) {
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
    std::set<unsigned long long> squares{};

    for (auto i{1ull}; i < 100ull; i++) squares.insert(i * i);
    build_primes(primes, 12'000ull);

    // dont have to test for odd if we only generate odd numbers
    for (auto i{13ull}; i < 10'000ull; i += 2) {
        // composite numbers are non - primes which are greater than 1
        if (!std::binary_search(primes.begin(), primes.end(), i)) {
            if (!std::any_of(primes.begin(), primes.end(), [&i, &squares](const auto& p) {
                    // relying on short circuiting for branchless programming
                    return ((p < i) && ((i - p) % 2ull == 0) && (squares.contains((i - p) / 2ull)));
                })) {
                std::cout << "Answer:\t" << i << "\n";
                break;
            }
        }
    }

    return 0;
}
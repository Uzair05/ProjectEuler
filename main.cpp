#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

template <typename T>
void generate_primes(std::vector<T>& primes, unsigned range) {
    if (primes.empty()) primes.emplace_back(2);

    for (T idx{primes.back() + 1}; idx < static_cast<T>(range); idx += 2) {
        if (std::none_of(primes.begin(), primes.end(),
                         [&idx](const auto& p) { return idx % p == 0; })) {
            primes.emplace_back(idx);
        }
    }
}

int main([[maybe_unused]] int argc, [[maybe_unused]] char const* argv[]) {
    std::vector<unsigned long long> primes{};
    generate_primes(primes, 800'000u);

    auto sum{0ull};
    for (auto p_ : primes) {
        if (p_ > 10) {
            auto p(p_);
            bool flag = true;
            while ((p > 0) && flag) {
                p = p / 10ull;
                if ((p > 0) && (!std::binary_search(primes.begin(), primes.end(), p))) {
                    flag = false;
                }
            }

            auto rp_{p_};
            auto max_trunc_range(100'000ull);  // number of zeros possible
            while ((rp_ > 0) && (flag)) {
                auto rp__ = rp_ % max_trunc_range;
                if (rp__ == rp_) {
                    max_trunc_range /= 10ull;
                } else {
                    rp_ = rp__;

                    if ((rp_ > 0) && (!std::binary_search(primes.begin(), primes.end(), rp_))) {
                        flag = false;
                    }
                }
            }

            if (flag) sum += p_;
        }
    }
    std::cout << sum << "\n";

    return 0;
}
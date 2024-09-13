#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

std::vector<unsigned long long>& generate_primes(std::vector<unsigned long long>& primes,
                                                 size_t range) {
    if (primes.empty()) {
        primes.push_back(2ull);
        primes.push_back(3ull);
    }

    for (size_t idx{primes.back()}; idx < range; idx += 2) {
        if (std::none_of(primes.begin(), primes.end(),
                         [&idx](const auto& a) { return idx % a == 0; })) {
            primes.push_back(idx);
        }
    }

    return primes;
}

inline bool is_pandigital(unsigned long long n) {
    std::map<unsigned long long, unsigned long long> nums{};
    auto i{1ull};
    auto n_{n};
    while (n_ > 0) {
        n_ /= 10ull;
        nums.insert(std::pair<unsigned long long, unsigned long long>(i++, 0ull));
    }

    while (n > 0) {
        if (nums.contains(n % 10ull)) {
            nums.at(n % 10ull) += 1ull;
        }
        n /= 10ull;
    }

    return std::all_of(nums.begin(), nums.end(), [](const auto& kv) { return kv.second == 1; });
}

int main([[maybe_unused]] int argc, [[maybe_unused]] char const* argv[]) {
    std::vector<unsigned long long> primes{};

    auto standing_primes_range{10'000'000ull};
    generate_primes(primes, standing_primes_range);
    auto res{std::find_if(primes.rbegin(), primes.rend(), [](auto n) { return is_pandigital(n); })};

    std::cout << ((res != primes.rend()) ? *res : 0ull) << "\n";
    std::cout << "Size of Primes:\t" << primes.size() << "\n";

    return 0;
}
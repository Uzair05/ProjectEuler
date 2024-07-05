#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
#include <math.h>

void get_primes(std::vector<int>& primes, int n) {
    if (primes.empty()) {
        primes.push_back(2);
    } else if (!std::is_sorted(primes.cbegin(), primes.cend())) {
        std::sort(primes.begin(), primes.end());
    }

    for (int i{*primes.rbegin()}; i < n; i++) {
        if (!std::any_of(primes.cbegin(), primes.cend(),
                         [&i](const auto& p) { return i % p == 0; })) {
            primes.push_back(i);
        }
    }
}

void get_factors(std::vector<int>& factors, const std::vector<int>& primes, int nom) {
    for (const auto& p : primes) {
        while (nom % p == 0) {
            factors.push_back(p);
            nom /= p;
        }
        if (nom == 0) {
            break;
        }
    }
}

int main([[maybe_unused]] int argc, [[maybe_unused]] char const* argv[]) {
    std::vector<int> primes{2};
    const int max_search_distance{20};

    get_primes(primes, max_search_distance + 1);

    std::map<int, int> m{};
    std::vector<int> factors{};

    for (int i{2}; i < max_search_distance; i++) {
        get_factors(factors, primes, i);

        std::map<int, int> tmp{};
        for (const auto& f : factors) {
            if (tmp.contains(f)) {
                ++(tmp.at(f));
            } else {
                tmp.insert(std::pair<int, int>(f, 1));
            }
        }

        for (const auto& [k, v] : tmp) {
            if (m.contains(k)) {
                if (m.at(k) < v) {
                    m.at(k) = v;
                }
            } else {
                m.insert(std::pair<int, int>(k, v));
            }
        }

        tmp.clear();
        factors.clear();
    }

    unsigned long long res{1};
    for (const auto& [k, v] : m) {
        res *= static_cast<unsigned long long>(std::pow(static_cast<long double>(k), static_cast<long double>(v)));
    }

    std::cout << res << "\r\n";

    return 0;
}
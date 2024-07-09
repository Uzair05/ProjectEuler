#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <vector>

void get_primes(std::vector<unsigned long long>& primes, unsigned long long n) {
    if (*primes.rbegin() < n) {  // we wish to prevent recalculations for primes
        std::cout << "Priming for:\t" << n << "\r\n";
        for (auto i{*primes.rbegin() + 1ull}; i <= n; i++) {
            if (!std::any_of(primes.begin(), primes.end(),
                             [&i](const auto& p) { return i % p == 0; })) {
                primes.push_back(i);
            }
        }

        size_t curr_size{
            primes
                .size()};  // find one more prime so that we can cut down on redundant calculations
        auto i{*primes.rbegin() + 1ull};
        while (primes.size() == curr_size) {
            if (!std::any_of(primes.begin(), primes.end(),
                             [&i](const auto& p) { return i % p == 0; })) {
                primes.push_back(i);
            }
            ++i;
        }
        std::cout << "Primed for:\t" << *primes.rbegin() << "\r\n";
    }
}

int main() {
    unsigned long long num{0};
    unsigned long long size_n{1};

    unsigned res{1};
    std::map<unsigned long long, unsigned> prime_factors{};
    std::vector<unsigned long long> primes{2};

    get_primes(primes, 12372);  // speed up the process; 

    while (res < 500) {
        num += size_n++;
        prime_factors.clear();
        res = 1u;

        auto n{num};
        while (n > 1) {
            for (const auto& p : primes) {

                while (n % p == 0) {
                    if (prime_factors.contains(p)) {
                        ++prime_factors.at(p);
                    } else {
                        prime_factors.insert(std::pair<unsigned long long, unsigned>(p, 1u));
                    }
                    n /= p;
                }

                if (n == 1) break;
            }

            if (n > 1) {
                get_primes(primes, num);
            }
        }

        // for(const auto& [_,v]: prime_factors){
        //     res *= (v+1);
        // }

        res = std::accumulate(
            prime_factors.begin(), prime_factors.end(), 1u,
            [](const unsigned& acc, const auto pf) { return acc * (pf.second + 1); });

        std::cout << num << ": " << res << "\r\n";
    }


    
    std::cout << "\r\n\nFinal:\t\t" << num << ": " << res << std::endl;
    return 0;
}
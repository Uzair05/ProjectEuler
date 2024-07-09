#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <vector>

void get_primes(std::vector<unsigned long long>& primes, unsigned long long n) {
    for (auto i{*primes.rbegin() + 1ull}; i <= n; i++) {
        if (!std::any_of(primes.begin(), primes.end(),
                         [&i](const auto& p) { return i % p == 0; })) {
            primes.push_back(i);
        }
    }
}

unsigned long long combination(unsigned long long n, unsigned long long r) {
    if (r == 1) return n;
    if (r == 0) return 1;
    if (r == n) return 1;

    auto n_{n};
    for (auto i{1ull}; i < r; i++) {
        n_ *= (n - i);
    }

    auto r_{r};
    for (auto i{1ull}; i < r; i++) {
        r_ *= (r - i);
    }

    return n_ / r_;
}

int main() {
    unsigned long long num{0};
    unsigned long long size_n{1};

    std::map<unsigned long long, int> prime_factors{};
    std::vector<unsigned long long> primes{2};

    // while (num<80) {

    //     num += size_n++;
    //     get_primes(primes, num);
    //     prime_factors.clear();

    //     auto n{num};
    //     while(n>1){
    //         for(const auto& p: primes){
    //             while (n%p == 0){
    //                 if (prime_factors.contains(p)){
    //                     ++prime_factors.at(p);
    //                 }else{
    //                     prime_factors.insert(std::pair<unsigned long long, int>(p, 1));
    //                 }
    //                 n /= p;
    //             }

    //             if (n == 1) break;
    //         }
    //     }

    //     std::cout << num << std::endl;
    //     for(const auto& [k,v]: prime_factors){
    //         std::cout << k << ", " << v << "\r\n";
    //     }
    // }

    for (auto i{0ull}; i < 21; i++) {
        std::cout << combination(20, i) << std::endl;
    }
    return 0;
}
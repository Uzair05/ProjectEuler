#include <algorithm>
#include <iostream>
#include <set>



void get_primes(std::set<unsigned long long>& primes, size_t n) {
    if (primes.empty()) {
        primes.insert(2);
    }

    unsigned long long i{*primes.rbegin()};
    while (primes.size() < n){
        if (!std::any_of(primes.cbegin(), primes.cend(),
                         [&i](const auto& p) { return i % p == 0; })) {
            primes.insert(i);
        }
        i++;
    }
}

int main() {
    std::set<unsigned long long> primes{2};
    
    get_primes(primes, 10001);
    std::cout << *primes.rbegin() << "\r\n";

    return 0;
}
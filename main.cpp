#include <iostream>
#include <numeric>
#include <set>
#include <vector>

int main([[maybe_unused]] int argc, [[maybe_unused]] char const *argv[]) {
    std::set<unsigned long long> amicable{};  // holds amicalble pairs

    std::vector<unsigned long long> factors{};
    for (auto n{4ull}; n < 10000ull; n++) {
        // if (amicable.contains(n)) {
        //     continue;
        // }

        factors.clear();
        for (auto m{1ull}; m < n; m++) {
            if (n % m == 0ull) factors.push_back(m);
        }
        auto opps_1 = std::accumulate(factors.begin(), factors.end(), 0ull);

        if (n == opps_1) {
            continue;
        }

        factors.clear();
        for (auto m{1ull}; m < opps_1; m++) {
            if (opps_1 % m == 0ull) factors.push_back(m);
        }
        auto opps_2 = std::accumulate(factors.begin(), factors.end(), 0ull);

        if (opps_2 == n) {
            // std::cout << "Amicable Pair: " << n << ", " << opps_1 << "\n";
            amicable.insert(n);
            amicable.insert(opps_1);
        }
    }

    std::cout << "\n\nSum of all pairs is: "
              << std::accumulate(amicable.begin(), amicable.end(), 0ull) << "\n";

    return 0;
}
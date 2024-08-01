#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

int main([[maybe_unused]] int argc, [[maybe_unused]] char const* argv[]) {
    const auto non_abundant_limit{
        28124u};  // this number and greater are all sum of abundant numbers

    std::vector<unsigned> list_of_abundant{};
    std::vector<unsigned> tmp{};

    for (unsigned i{1u}; i < non_abundant_limit; i++) {
        tmp.clear();
        for (unsigned j{1u}; j < i; j++) {
            if (i % j == 0) tmp.push_back(j);
        }
        if (std::accumulate(tmp.begin(), tmp.end(), 0u) > i) list_of_abundant.push_back(i);
    }

    std::vector<unsigned> list_of_non_abundant_sum(23);
    std::iota(list_of_non_abundant_sum.begin(), list_of_non_abundant_sum.end(), 1u);

    for (unsigned i{24}; i < non_abundant_limit; i++) {
        bool flg{false};
        for (const auto& abnd : list_of_abundant) {
            flg |=
                (std::binary_search(list_of_abundant.begin(), list_of_abundant.end(), (i - abnd)));

            if (flg) {
                break; //short circuit; could have used reduce or accumulate
            }
        }

        if (!flg) {
            list_of_non_abundant_sum.push_back(i);
        }
    }

    std::cout << std::accumulate(list_of_non_abundant_sum.begin(), list_of_non_abundant_sum.end(),
                                 0u)
              << std::endl;

    return 0;
}
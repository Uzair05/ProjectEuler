#include <cstddef>
#include <iostream>
#include <vector>
#include "large_number.hpp"

large_number<unsigned> add(const large_number<unsigned>& n1, const large_number<unsigned>& n2) {
    large_number<unsigned> ret{};
    unsigned carry{0};
    unsigned res{0};

    unsigned long i{0ul};
    for (; i < ((n1.size() < n2.size()) ? n1.size() : n2.size()); i++) {
        res = n1.num[i] + n2.num[i] + carry;
        ret.num.push_back(res % 10);
        carry = res / 10;
    }

    while (i < n1.size()) {
        res = n1.num[i] + carry;
        ret.num.push_back(res % 10);
        carry = res / 10;

        i++;
    }
    while (i < n2.size()) {
        res = n2.num[i] + carry;
        ret.num.push_back(res % 10);
        carry = res / 10;

        i++;
    }
    while (carry > 0) {
        ret.num.push_back(carry % 10);
        carry /= 10;
    }

    return ret;
}

void println(large_number<unsigned>& n) {
    for (auto it{n.num.rbegin()}; it != n.num.rend(); it++) {
        std::cout << *it;
    }
    std::cout << "\n";
}
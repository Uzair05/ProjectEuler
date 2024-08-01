#include <algorithm>
#include <deque>
#include <iostream>
#include <numeric>

template <typename T>
void massive_mulitple(std::deque<T>& dst, T n) {
    T carry{0};

    for (auto& idx : dst) {
        carry = (idx * n) + carry;
        idx = carry % 10u;
        carry /= 10u;
    }

    while (carry > 0) {
        dst.push_back(carry % 10u);
        carry /= 10;
    }
}

template <typename T>
void massive_self_power(std::deque<T>& dst, T init_number, T i) {
    dst.clear();
    dst.push_back(1);
    for (T idx{0}; idx < i; idx++) {
        massive_mulitple(dst, init_number);
    }
}

int main([[maybe_unused]] int argc, [[maybe_unused]] char const* argv[]) {
    // Add code

    std::deque<unsigned long long> m{};
    std::deque<unsigned long long> tmp{};

    unsigned long long res{0};
    for (unsigned long long i{1}; i < 1000; i++) {
        if (i % 10 != 0) {
            tmp.clear();                  // cache to hold last 12 digits
            massive_self_power(m, i, i);  // massive number solved for power

            std::for_each(
                m.begin(), ((m.size() > 12) ? m.begin() + 12 : m.end()),
                [&tmp](const auto& n) { tmp.push_front(n); });  // trim down to last 12 numbers
            res += std::accumulate(tmp.begin(), tmp.end(), 0ull, [](auto acc, const auto& n) {
                return (acc * 10) + n;
            });  // build a real number and add together
        }
    }

    std::cout << res % 10000000000 << "\n";  // only need last 10 digits

    return 0;
}
#include <iostream>
#include <limits>
#include <map>

using ull = unsigned long long;

ull inc_denom(unsigned digit, unsigned depth, std::map<unsigned, std::map<unsigned, ull>>& m) {
    if (depth == 1u) return 1ull;

    if (m.contains(depth) && m.at(depth).contains(digit)) {
        return m.at(depth).at(digit);
    }

    ull res{0ull};
    for (unsigned idx{0u}; idx <= digit; idx++) res += inc_denom(idx, depth - 1, m);

    if (m.contains(depth)) {
        m.at(depth).insert(std::pair<unsigned, ull>(digit, res));
    } else {
        auto m_ = std::map<unsigned, ull>{{digit, res}};
        m.insert(std::pair<unsigned, std::map<unsigned, ull>>(depth, m_));
    }

    return res;
}

ull dec_denom(unsigned digit, unsigned depth, std::map<unsigned, std::map<unsigned, ull>>& m) {

    if (depth == 1u) return 1ull;
    
    if (m.contains(depth) && m.at(depth).contains(digit)) {
        return m.at(depth).at(digit);
    }

    ull res{0ull};
    for (unsigned idx{digit}; idx <= 9u; idx++) res += dec_denom(idx, depth - 1, m);

    if (m.contains(depth)) {
        m.at(depth).insert(std::pair<unsigned, ull>(digit, res));
    } else {
        auto m_ = std::map<unsigned, ull>{{digit, res}};
        m.insert(std::pair<unsigned, std::map<unsigned, ull>>(depth, m_));
    }

    return res;
}

int main([[maybe_unused]] int argc, [[maybe_unused]] char const* argv[]) {
    std::map<unsigned, std::map<unsigned, ull>> m_1{};
    ull acc_i{inc_denom(1, 11, m_1)};
    for (auto i{10u}; i > 0u; i--) {
        acc_i += inc_denom(9u, i, m_1);
    }
    m_1.clear();

    std::map<unsigned, std::map<unsigned, ull>> m_2{};
    // ull acc_d{dec_denom(1, 11, m_2)};
    ull acc_d{0ull};
    for (auto i{11u}; i > 0u; i--) {
        acc_d += dec_denom(0u, i, m_2);
    }

    m_2.clear();

    std::cout << acc_i + acc_d << "\n";
    std::cout << std::numeric_limits<ull>::max() << "\n";
    std::cout << dec_denom(9u, 11u, m_2); << "\n";
    
    return 0;
}
#include <set>
#include <vector>
#include <future>
#include "pandigital.hpp"


bool pandigital_start(const std::vector<unsigned>& n) {
    std::set<unsigned> cs{};
    for (auto it{n.rbegin()}; it != (std::distance(n.rbegin(), n.rend())>=9 ? n.rbegin() + 9 : n.rend()); it++) {
        cs.insert(*it);
    }
    return (cs.size() == 9ul && !cs.contains(0));
}

bool pandigital_end(const std::vector<unsigned>& n) {
    std::set<unsigned> cs{};
    for (auto it{n.begin()}; it != (std::distance(n.begin(), n.end())>=9 ? n.begin() + 9 : n.end()); it++) {
        cs.insert(*it);
    }
    return (cs.size() == 9ul && !cs.contains(0));
}

bool pandigital_dual(const std::vector<unsigned>& n) { 
    auto e = std::async(std::launch::async, pandigital_end, n);
    auto f = std::async(std::launch::async, pandigital_start, n);

    e.wait(); f.wait();
    return (n.size()>=9ul && e.get() && f.get()); 
}
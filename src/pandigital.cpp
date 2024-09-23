#include <set>
#include <vector>
#include "pandigital.hpp"


bool pandigital_start(std::vector<unsigned>& n) {
    std::set<unsigned> cs{};
    for (auto it{n.rbegin()}; it != n.rend() && it != (n.rbegin() + 9); it++) {
        if (cs.contains(*it)) {
            return false;
        } else {
            cs.insert(*it);
        }
    }
    return !cs.contains(0);
}

bool pandigital_end(std::vector<unsigned>& n) {
    std::set<unsigned> cs{};
    for (auto it{n.begin()}; it != n.end() && it != (n.begin() + 9); it++) {
        if (cs.contains(*it)) {
            return false;
        } else {
            cs.insert(*it);
        }
    }
    return !cs.contains(0);
}

bool pandigital_dual(std::vector<unsigned>& n) { 
    return (n.size()>=9ul && pandigital_end(n) && pandigital_start(n)); 
}
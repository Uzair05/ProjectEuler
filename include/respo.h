#ifndef INCLUDE_RESPO_H
#define INCLUDE_RESPO_H

#include <limits>
#include <numeric>
#include <vector>

namespace respo {
    template <typename T>
    T max_value(const std::vector<T>& v);

    template <typename T>
    T min_value(const std::vector<T>& v);
};  // namespace respo

#endif
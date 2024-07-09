#include "respo.h"

namespace respo {
    template <typename T>
    T max_value(const std::vector<T>& v) {
        return std::accumulate(v.begin(), v.end(), std::numeric_limits<T>::min(),
                               [](const T& s, const T& a) { return ((s > a) ? s : a); });
    };

    template <typename T>
    T min_value(const std::vector<T>& v) {
        return std::accumulate(v.begin(), v.end(), std::numeric_limits<T>::max(),
                               [](const T& s, const T& a) { return ((s < a) ? s : a); });
    };
};  // namespace respo
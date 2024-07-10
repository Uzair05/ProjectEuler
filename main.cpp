#include <iostream>

struct counts_ {
    unsigned count{0};
    unsigned start_number{0};
};

int main() {
    auto even_fn = [](const unsigned n) { return n / 2u; };
    auto odd_fn = [](const unsigned n) { return ((n * 3u) + 1u); };

    counts_ count_{};
    unsigned count{};

    for (unsigned i{0}; i < 1'000'000; i++) {
        count = 0;

        unsigned i_{i};
        while (i_ > 1) {
            if ((i_ % 2) == 0) {
                i_ = even_fn(i_);
            } else {
                i_ = odd_fn(i_);
            }
            ++count;
        }

        if (count_.count < count) {
            count_.count = count;
            count_.start_number = i;
        }
    }

    std::cout << count_.start_number << "\r\n";

    return 0;
}
#include <iostream>

struct num_anal {
    unsigned int_counts[10];

    num_anal() : int_counts{{}} {
        for (size_t i{0ul}; i < 10ul; i++) {
            int_counts[i] = 0;
        }
    }

    void insert(unsigned long long i) {
        if (i < 10) {
            this->int_counts[static_cast<size_t>(i)] += 1u;
        } else {
            while (i > 0) {
                this->int_counts[static_cast<size_t>(i % 10ull)] += 1u;
                i /= 10ull;
            }
        }
    }

    void print() {
        for (size_t i{0ul}; i < 10ul; i++) {
            std::cout << this->int_counts[i] << ", ";
        }
        std::cout << "\n";
    }

    bool operator==(const num_anal& t) {
        for (size_t i{0ul}; i < 10ul; i++) {
            if (this->int_counts[i] != t.int_counts[i]) {
                return false;
            }
        }
        return true;
    }
};

int main([[maybe_unused]] int argc, [[maybe_unused]] char const* argv[]) {
    for (auto i{1ull}; i < 1'000'000ull; i++) {
        num_anal x[5];
        for (auto m{2ull}; m < 7ull; m++) {
            x[static_cast<size_t>(m - 2ull)].insert(m * i);
        }
        if ((x[0] == x[1]) && (x[0] == x[2]) && (x[0] == x[3]) && (x[0] == x[4])) {
            std::cout << "Found Answer:\t" << i << std::endl;
            break;
        }
    }

    return 0;
}
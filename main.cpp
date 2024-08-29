#include <iostream>
#include <map>
#include <memory>
#include <vector>

using pyr = std::vector<std::vector<unsigned long long>>;

struct node {
    unsigned long long val;

    bool has_val;
    unsigned long long acc;
    std::shared_ptr<node> l;
    std::shared_ptr<node> r;

    node(unsigned long long v) : val{v}, l{nullptr}, r{nullptr}, acc{0}, has_val{false} {}
};

unsigned long long evaluate_pyramid(std::shared_ptr<node> head) {
    if ((head->l == nullptr) && (head->r == nullptr)) return head->val;
    if (head->has_val) return head->acc;

    unsigned long long left_val{(head->l != nullptr) ? evaluate_pyramid(head->l) : 0};
    unsigned long long right_val{(head->r != nullptr) ? evaluate_pyramid(head->r) : 0};
    unsigned long long val{head->val + ((left_val > right_val) ? left_val : right_val)};

    head->has_val = true;
    head->acc = val;

    return val;
}

int main([[maybe_unused]] int argc, [[maybe_unused]] char const *argv[]) {
    pyr pyramid{{75},
                {95, 64},
                {17, 47, 82},
                {18, 35, 87, 10},
                {20, 04, 82, 47, 65},
                {19, 01, 23, 75, 03, 34},
                {88, 02, 77, 73, 07, 63, 67},
                {99, 65, 04, 28, 06, 16, 70, 92},
                {41, 41, 26, 56, 83, 40, 80, 70, 33},
                {41, 48, 72, 33, 47, 32, 37, 16, 94, 29},
                {53, 71, 44, 65, 25, 43, 91, 52, 97, 51, 14},
                {70, 11, 33, 28, 77, 73, 17, 78, 39, 68, 17, 57},
                {91, 71, 52, 38, 17, 14, 91, 43, 58, 50, 27, 29, 48},
                {63, 66, 04, 68, 89, 53, 67, 30, 73, 16, 69, 87, 40, 31},
                {04, 62, 98, 27, 23, 9, 70, 98, 73, 93, 38, 53, 60, 04, 23}};

    // Filling Pyramid into a tree like structure for easy traversal
    std::shared_ptr<node> head = std::shared_ptr<node>(new node(pyramid[0][0]));
    std::vector<std::shared_ptr<node>> prev_row{head};
    std::vector<std::shared_ptr<node>> curr_row{};

    for (size_t row{1}; row < pyramid.size(); row++) {
        for (size_t idx{0}; idx < (row + 1); idx++) {
            std::shared_ptr<node> tmp{new node(pyramid[row][idx])};

            if (idx != 0) prev_row[idx - 1]->r = tmp;
            if (idx != row) prev_row[idx]->l = tmp;

            curr_row.emplace_back(tmp);
        }
        prev_row = curr_row;
        curr_row.clear();
    }

    std::cout << evaluate_pyramid(head) << "\n\n\n";

    return 0;
}
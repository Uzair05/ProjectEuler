#include <iostream>
#include <vector>

bool is_palindrome(int n) {
    int m{0}, x{n};

    while (x > 0) {
        m *= 10;
        m += x % 10;
        x /= 10;
    }

    return m == n;
}

bool is_two_numbers(int n) {
    for (int i{100}; i < 1000; i++) {
        if (((n % i) == 0) && (((n / i) > 100) && ((n / i) < 1000))) return true;
    }
    return false;
}

int main([[maybe_unused]] int argc, [[maybe_unused]] char const *argv[]) {
    int largest_multiple{999 * 999};
    int smallest_multiple{100 * 100};

    for (int i{largest_multiple}; i >= smallest_multiple; i--) {
        if (is_palindrome(i) && is_two_numbers(i)) {
            std::cout << i << "\r\n";
            break;
        }
    }

    return 0;
}
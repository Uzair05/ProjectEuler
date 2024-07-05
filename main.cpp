#include <iostream>

int main([[maybe_unused]] int argc, [[maybe_unused]] char const *argv[]) {

    unsigned long long s_1{0};
    unsigned long long s_2{0};

    for (unsigned long long i{0}; i<100; i++){
        s_1 += i*i;
    }
    for (unsigned long long i{0}; i<100; i++){
        s_2 += i;
    }
    s_2 *= s_2;

    std::cout << s_2 - s_1 << "\r\n";

    // Add code

    return 0;
}
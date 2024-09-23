#include <iostream>
#include <numeric>
#include <vector>

#include "large_number.hpp"
#include "pandigital.hpp"

int main([[maybe_unused]] int argc, [[maybe_unused]] char const *argv[]) {
    large_number<unsigned> n1(0ull);
    large_number<unsigned> n2(1ull);
    large_number<unsigned> n3(1ull);


    std::cout << std::boolalpha;
    size_t i{0};
    while(!pandigital_dual(n3.num)){
        n1 = std::move(n2);
        n2 = std::move(n3);
        n3 = add(n1, n2);
        i++;
    }

    println(n3);
    std::cout << i+2 << "\n";



    


    return 0;
}
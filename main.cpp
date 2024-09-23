#include <iostream>
#include <vector>

#include "pandigital.hpp"


void add(std::vector<unsigned>& dst, std::vector<unsigned>& n1, std::vector<unsigned>& n2){
    dst.clear();
    unsigned carry{0u}, res{0u};

    size_t i{0ul};
    for(; i<((n1.size()<n2.size())?n1.size():n2.size()); i++){
        res = n1[i] + n2[i] + carry;
        dst.push_back(res%10u);
        carry = res/10u;    
    }

    while(i < n1.size()){
        res = n1[i] + carry;
        dst.push_back(res%10u);
        carry = res/10u; 
        i++;
    }
    while(i < n2.size()){
        res = n2[i] + carry;
        dst.push_back(res%10u);
        carry = res/10u; 
        i++;
    }
    while (carry>0){
        dst.push_back(carry%10u);
        carry /= 10u;
    }
}


int main([[maybe_unused]] int argc, [[maybe_unused]] char const *argv[]) {
    std::vector<unsigned> num[3]{{0u},{1u},{1u}};

    size_t i{0};
    for(; i<100ul; i++){
        add(num[i%3], num[(i+1)%3], num[(i+2)%3]);
    }

    while(!pandigital_dual(num[i%3])){
        add(num[i%3], num[(i+1)%3], num[(i+2)%3]);
        i++;
    }

    std::cout << i << "\n";
    


    return 0;
}
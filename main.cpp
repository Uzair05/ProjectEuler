#include <iostream>
#include <deque>

void multiply(std::deque<unsigned>& res, unsigned n) {
    auto carry{0u};
    for(auto& i: res){
        i = (i*n + carry);
        carry = i/10u;
        i = i%10u;
    }

    while (carry > 0){
        res.push_back(carry%10u);
        carry = carry/10u;
    }
}


void factorial(std::deque<unsigned>& res, unsigned n){
    while (n>1){
        multiply(res, n);
        n-=1u;
    }
}

int main([[maybe_unused]] int argc, [[maybe_unused]] char const *argv[]) {
    
    std::deque<unsigned> num{1};
    factorial(num, 99);

    for (auto it{num.rbegin()}; it!=num.rend(); it++){
        std::cout << *it;
    }std::cout << "\n";

    return 0;
}
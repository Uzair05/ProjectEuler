#include <iostream>
#include <deque>

void multiply(std::deque<unsigned long long>& res, unsigned long long n) {
    auto carry{0ull};
    for(auto& i: res){
        i = (i*n + carry);
        carry = i/10ull;
        i = i%10ull;
    }

    while (carry > 0){
        res.push_back(carry%10ull);
        carry = carry/10ull;
    }
}


void factorial(std::deque<unsigned long long>& res, unsigned long long n){
    while (n>1ull){
        multiply(res, n);
        n-=1ull;
    }
}

int main([[maybe_unused]] int argc, [[maybe_unused]] char const *argv[]) {
    
    std::deque<unsigned long long> num{1};
    factorial(num, 99);

    // for (auto it{num.rbegin()}; it!=num.rend(); it++){
    //     std::cout << *it;
    // }std::cout << "\n";


    unsigned long long res{0};
    for(const auto& i: num){
        res+=i;
    }
    std::cout << res << "\n";

    return 0;
}
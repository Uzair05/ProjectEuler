#include <iostream>
#include <vector>
#include <algorithm>
#include <future>

bool num_inc(const std::vector<unsigned>& n){
    if (n[0] < n.back()) return false;

    for(size_t i{0ul}; i<(n.size()-1); i++){
        if (n[i] < n[i+1]){
            return false;
        }
    }
    return true;
}

bool num_dec(const std::vector<unsigned>& n){
    if (n[0] > n.back()) return false;

    for(size_t i{0ul}; i<(n.size()-1); i++){
        if (n[i] > n[i+1]){
            return false;
        }
    }
    return true;
}

bool num_bouncy(const std::vector<unsigned>& n){
    // auto a = std::async(std::launch::async, [](const std::vector<unsigned>& n_){return num_dec(n_);}, n);
    // auto b = std::async(std::launch::async, [](const std::vector<unsigned>& n_){return num_inc(n_);}, n);

    // a.wait(); b.wait();
    // return !(a.get() || b.get());

    return !(num_dec(n) || num_inc(n));
}


void increment(std::vector<unsigned>& n){

    unsigned res{0u};
    unsigned carry{1u};
    for(auto& c: n){
        res = c + carry;
        c = res%10;
        carry = res/10u;

        if (carry==0u) break;
    }

    while(carry>0){
        n.push_back(carry%10u);
        carry /= 10u;
    }

}


int main([[maybe_unused]] int argc, [[maybe_unused]] char const *argv[]) {

    std::vector<unsigned> num{0u, 0u, 1u};
    std::vector<unsigned> counter{0u};


    auto k = 0ull;
    for(auto j{0ull}; j<10'000'000'000; j++){
        for(auto i{0ull}; i<10'000'000'000; i++){
            // increment(num);
            // if (!num_bouncy(num)) increment(counter);
            k++;
        }
        k = 0ull;
        std::cout << j << "\n";
    }

    std::cout << "\n\n\n";
    for(auto it{counter.rbegin()}; it!=counter.rend(); it++){
        std::cout << *it;
    }std::cout << "\n";

    
    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

using ull = unsigned long long;

bool num_dec(ull n){
    std::vector<ull> nums{};
    while(n>0){
        nums.push_back(n%10ull);
        n/=10ull;
    }
    std::reverse(nums.begin(), nums.end());
    
    for(size_t idx{0ul}; idx<(nums.size()-1); idx++){
        if (nums[idx] < nums[idx+1]) return false;
    }
    return true;
}

bool num_inc(ull n){
    std::vector<ull> nums{};
    while(n>0){
        nums.push_back(n%10ull);
        n/=10ull;
    }
    std::reverse(nums.begin(), nums.end());
    
    for(size_t idx{0ul}; idx<(nums.size()-1); idx++){
        if (nums[idx] > nums[idx+1]) return false;
    }
    return true;
}

bool num_bouncy(ull n){
    return !(num_inc(n) || num_dec(n));
}


int main([[maybe_unused]] int argc, [[maybe_unused]] char const *argv[]) {
    
    auto idx{100ull};
    auto counter{0ull};
    while(!((idx%100ull==0ull) && ((idx/100ull)*99ull == counter))){
        idx++;
        if (num_bouncy(idx)) ++counter;
    }

    std::cout << "Least Bouncy:\t" << idx << "\n" ;

    
    return 0;
}
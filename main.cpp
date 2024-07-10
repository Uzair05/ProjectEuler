#include <iostream>
#include <vector>
#include <numeric>

int main() {

    auto even_fn = [](const unsigned n){return n/2u;};
    auto odd_fn =  [](const unsigned n){return ((n*3u)+1u);};
    
    std::vector<unsigned> counts_{};
    unsigned count{};
    
    for(unsigned i{0}; i<1'000'000; i++){
        count = 0;

        unsigned i_{i};
        while(i_ > 1){
            if ((i_%2)==0){
                i_ = even_fn(i_);
            }else{
                i_ = odd_fn(i_);
            }
            ++count;
        }

        counts_.push_back(count);
    }


    std::cout << 
        std::distance(counts_.begin(), std::find(counts_.begin(), counts_.end(), std::accumulate(counts_.begin(), counts_.end(), 0u, [](auto acc, auto& n){return ((acc>n)?acc:n);})))
        << "\r\n";

    return 0;
}
#include <iostream>
#include <deque>


void add(std::deque<unsigned>& m, unsigned n){

    auto carry{n};

    for(auto& i: m){
        i = (i+carry);
        carry = i/10u;
        i = i%10u;
    }

    while (carry>0){
        m.push_back(carry%10u);
        carry /= 10u;
    }
    
}





void add(std::deque<unsigned>& res, std::deque<unsigned>& x, std::deque<unsigned>& y){

    res.clear(); // empty res for overwriting
    auto carry{0u};
    auto min_sz {(x.size() < y.size())?x.size():y.size()};
    // auto max_sz {(x.size() > y.size())?x.size():y.size()};

    auto idx{0ul};
    for(; idx<min_sz; idx++){
        auto i = x[idx] + y[idx] + carry;
        res.push_back(i%10u);
        carry = i/10u;
    }

    while (idx < x.size()){
        auto i = x[idx] + carry;
        res.push_back(i%10u);
        carry = i/10u;

        idx++;
    }
    while (idx < y.size()){
        auto i = y[idx] + carry;
        res.push_back(i%10u);
        carry = i/10u;

        idx++;
    }

    while(carry>0){
        res.push_back(carry%10u);
        carry /= 10u;
    }

}



int main([[maybe_unused]] int argc, [[maybe_unused]] char const *argv[]) {
    
    std::deque<unsigned> x{};
    std::deque<unsigned> y{1u};
    std::deque<unsigned> z{1u};
    
    
    for(auto n{3}; n<=100000; n++){
        x = y;
        y = z;
        add(z, x, y);

        if ((z.size())>=1000){
            std::cout << "1000 digits at: " << n << "\n";
            break;
        }
    }

    for(auto it{z.rbegin()}; it!=z.rend(); it++){
        std::cout << *it;
    }std::cout << "\n";

    return 0;
}
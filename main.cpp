#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>



void generate_triangle_numbers(std::vector<unsigned long>& dst, size_t range){
    for(size_t i{dst.size()+1}; i < range; i++){
        dst.push_back((i*(i+1ul))/2ul);
    }
}




int main([[maybe_unused]] int argc, [[maybe_unused]] char const *argv[]) {
    std::vector<unsigned long> tri_num{};
    generate_triangle_numbers(tri_num, 30);

    std::ifstream file;
    unsigned long long counter{0};

    file.open("./input.txt");
    if (file.is_open()){
        for(std::string line; getline(file, line, ',');){
            unsigned long add{0};
            for(char& c: line.substr(1, line.size()-2)){
                add += (c-'A')+1;
            }

            while (tri_num.back() <= add){
                generate_triangle_numbers(tri_num, tri_num.size()+10);
            }

            if (std::binary_search(tri_num.begin(), tri_num.end(), add)){
                counter++;
            }
        }

    }else{
        std::cout << "File Open Failure\n";
        return 1;
    }

    std::cout << "\nCase Size:\t" << tri_num.size() <<"\n";
    std::cout << "Counter is:\t" << counter << "\n";

    file.close();


    return 0;
}
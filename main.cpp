#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <bitset>

int main([[maybe_unused]] int argc, [[maybe_unused]] char const* argv[]) {
    std::vector<char> file_data{};
    std::ifstream file;
    file.open("./0059_cipher.txt");

    if (file.is_open()) {
        for (std::string buffer{}; std::getline(file, buffer, ',');) {
            file_data.push_back(static_cast<char>(std::stoul(buffer)));
        }
        file.close();
    } else {
        std::cout << "File opening error\n";
        return 1;
    }
	if(file_data.empty()){
		std::cout << "File was empty\n";
        return 1;
	}





    auto is_character = [](const char& c_) {
        return (((c_ >= 'a') &&
                 (c_ <= 'z')) ||
                ((c_ >= 'A') &&
                 (c_ <= 'Z')));
    };
	
	
	bool found_flag{false};
	bool emr{false};
	char crypt_1 = 'a';
	while(!found_flag && !emr){
		found_flag = true;
		std::cout << "Crypt is: " << crypt_1 << "\n";
		for(size_t counter{0}; counter < file_data.size(); counter+=3){
			if (!is_character(file_data[counter] ^ crypt_1)){
				++crypt_1;
				found_flag = false;
				if (crypt_1 > 'z'){
					std::cout << "Cant Find Crypt 1\n";
					emr = true;
				}
				break;
			}
		}
	}


    // if (file_data.empty()) {
        // std::cout << "File was empty\n";
        // return 1;
    // } else {
    //     unsigned long crypt[3] = {static_cast<unsigned long>('a')};
    //     bool flag{false};

    //     while (!flag) {
    //         flag = true;
    //         for (size_t counter{0}; (counter + 2) < file_data.size(); counter += 3) {
    //             if (!(is_character(file_data[counter] ^ crypt[0]) &&
    //                   is_character(file_data[counter + 1] ^ crypt[1]) &&
    //                   is_character(file_data[counter + 2] ^ crypt[2]))) {
    //                 flag = false;
    //                 std::cout << "Hit Break " << crypt[0] << " " << crypt[1] << " " << crypt[2] << "Counter at:\t" << counter << "\n";

    //                 if (!(is_character(file_data[counter] ^ crypt[0]))) {
    //                     crypt[0]++;
	// 					crypt[0] = (crypt[0] > static_cast<unsigned long>('z')) ? static_cast<unsigned long>('a') : crypt[0];
    //                 }
    //                 if (!(is_character(file_data[counter + 1] ^ crypt[1]))) {
    //                     crypt[1]++;
	// 					crypt[1] = (crypt[1] > static_cast<unsigned long>('z')) ? static_cast<unsigned long>('a') : crypt[1];
    //                 }
    //                 if (!(is_character(file_data[counter + 2] ^ crypt[2]))) {
    //                     crypt[2]++;
	// 					crypt[2] = (crypt[2] > static_cast<unsigned long>('z')) ? static_cast<unsigned long>('a') : crypt[2];
    //                 }
    //             }
    //         }
    //     }
	// 	std::cout << "Hit Found" << crypt[0] << crypt[1] << crypt[2] << "\n";
    // }

	

    return 0;
}
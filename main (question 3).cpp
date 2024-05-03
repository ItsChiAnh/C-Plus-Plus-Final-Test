#include <iostream>
#include <string>

std::string encodeRLE(const std::string& s) {
    std::string encoded;
    int count = 1; 

    for (int i = 1; i <= s.length(); i++) {
        if (i < s.length() && s[i] == s[i-1]) {
            count++; // Tăng số lần đếm nếu ký tự liên tiếp giống nhau
        } else {
            // Ghi nhận ký tự và số lần xuất hiện vào chuỗi kết quả
            encoded += s[i-1]; 
            encoded += std::to_string(count); // Thêm số lần loop
            count = 1; 
        }
    }

    return encoded;
}

int main() {
    std::string input;
    std::cout << "Enter a string: ";
    std::cin >> input;
    std::string encoded = encodeRLE(input);
    std::cout << "Encoded string: " << encoded << std::endl;
    return 0;
}


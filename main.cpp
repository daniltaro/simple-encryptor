#include "cryption/Crypt.h"
#include <iostream>

int main() {
    std::string file_path;
    std::fstream f_stream;
    int status;
    int key;

    try {
        std::cout << "Enter the file path: ";
        std::getline(std::cin, file_path);

        f_stream.open(file_path, std::ios::in | std::ios::out | std::ios::binary);
        if (!f_stream.is_open()) {
            throw std::runtime_error(file_path);
        }

        std::cout << "Encrypt or Decrypt (1/2): ";
        std::cin >> status;
        if (std::cin.fail() || (status != 1 && status != 2)) {
            throw std::runtime_error("Invalid choice for encrypt/decrypt");
        }

        std::cout << "Enter the key: ";
        std::cin >> key;
        if (std::cin.fail()) {
            throw std::runtime_error("Invalid key");
        }

        if (status == 1) {
            Cryption cr(std::move(f_stream), file_path, key);
            cr.enc();
            std::cout << "File was encrypted" << std::endl;
        } else {
            Cryption cr(std::move(f_stream), file_path, key);
            cr.dec();
            std::cout << "File was decrypted" << std::endl;
        }
    } catch (const std::runtime_error &e) {
        std::cerr << "File open error: " << e.what() << std::endl;
    }

    return 0;
}
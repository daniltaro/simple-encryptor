#include "Crypt.h"

Cryption::Cryption(std::fstream &&stream, const std::string &file, const int &k): f_stream(std::move(stream)),
    file_path(file), key(k) {
    if (!f_stream) {
        throw std::runtime_error("Invalid file stream");
    }
}

Cryption::~Cryption() {
    f_stream.close();
}

void Cryption::dec() {
    char ch;
    while (f_stream.get(ch)) {
        ch = (ch - key + 256) % 256;
        f_stream.seekp(-1, std::ios::cur);
        if (f_stream.fail()) {
            throw std::runtime_error("Failed to seek in file");
        }
        f_stream.put(ch);
    }
}

void Cryption::enc() {
    char ch;
    while (f_stream.get(ch)) {
        ch = (ch + key) % 256;
        f_stream.seekp(-1, std::ios::cur);
        if (f_stream.fail()) {
            throw std::runtime_error("Failed to seek in file");
        }
        f_stream.put(ch);
    }
}

#ifndef CRYPT_H
#define CRYPT_H

#include <fstream>
#include <string>

class Cryption {
private:
    std::fstream f_stream;
    std::string file_path;
    int key;

public:
    void enc();

    void dec();

    Cryption(std::fstream &&stream, std::string file, int k);

    ~Cryption();
};

#endif

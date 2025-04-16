cmake_minimum_required(VERSION 3.30)
project(simple_encryptor)

set(CMAKE_CXX_STANDARD 20)

add_executable(simple_encryptor src/main.cpp
        src/cryption/Crypt.cpp
)

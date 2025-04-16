# Simple Encryptor

A lightweight C++ tool for encrypting and decrypting binary files using a custom Caesar-like cipher.

## Features

- Simple byte-wise encryption and decryption
- Works with any binary file type
- Easy to use terminal interface

## Usage

1. **Compile the project** using CMake or your preferred method.
2. **Run the program** and follow the prompts:
    - Enter the path to the file
    - Choose to encrypt (1) or decrypt (2)
    - Enter an integer key

## Example

```bash
Enter the file path: test.txt
Encrypt or Decrypt (1/2): 1
Enter the key: 7
File was encrypted
```

## Notes
- Make sure the file is not open in another program.
- This is a basic encryption method for educational/demo purposes only.

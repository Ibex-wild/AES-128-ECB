# AES-128 ECB

My first cryptography implementation in C++.

A simple implementation of **AES-128 encryption and decryption using ECB mode**.

## Features

* AES-128
* ECB mode
* Encryption & decryption
* 128-bit key
* 16-byte block size
* PKCS#7-style padding

## Files

```text
AES-128-ECB.cpp
AES-128-ECB.h
README.md
LICENSE
```

## Build

```bash
g++ -std=c++17 -O3 -march=native -flto -funroll-loops -finline-functions-called-once aes128.cpp -o aes128
```

## Note

This project was created for **learning and experimentation with cryptography**.

**ECB mode is not recommended for protecting sensitive data in real-world applications.**

## License

MIT License © 2026 aerovyn QueQue

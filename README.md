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

MIT License

Copyright (c) 2026 QueQue

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

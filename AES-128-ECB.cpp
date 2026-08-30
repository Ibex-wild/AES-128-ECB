/*
 * MIT License
 *
 * Copyright (c) 2026 QueQue
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
 
#include "AES-128-ECB.h"
#include <iostream>
#include <vector>
#include <cstring>
#include <stdexcept>

using namespace std;

vector<unsigned char> aes_ecb_encrypt_raw(
    const vector<unsigned char>& plaintext,
    const unsigned char* key)
{
    if (plaintext.size() % AES_BLOCK_SIZE != 0) {
        throw runtime_error("Plaintext length must be multiple of 16");
    }

    vector<unsigned char> ciphertext(plaintext.size());
    memcpy(ciphertext.data(), plaintext.data(), plaintext.size());

    AES_CTX ctx;
    AES_EncryptInit(&ctx, key);
    AES_Encrypt(&ctx, ciphertext.data(),
                static_cast<unsigned int>(ciphertext.size()),
                ciphertext.data());
    AES_CTX_Free(&ctx);

    return ciphertext;
}

vector<unsigned char> aes_ecb_decrypt_raw(
    const vector<unsigned char>& ciphertext,
    const unsigned char* key)
{
    if (ciphertext.size() % AES_BLOCK_SIZE != 0) {
        throw runtime_error("Ciphertext length must be multiple of 16");
    }

    vector<unsigned char> plaintext(ciphertext.size());

    AES_CTX ctx;
    AES_DecryptInit(&ctx, key);
    AES_Decrypt(&ctx, ciphertext.data(),
                static_cast<unsigned int>(ciphertext.size()),
                plaintext.data());
    AES_CTX_Free(&ctx);

    return plaintext;
}

vector<unsigned char> aes_ecb_encrypt(
    const vector<unsigned char>& plaintext,
    const unsigned char* key)
{
    size_t pad_len = AES_BLOCK_SIZE - (plaintext.size() % AES_BLOCK_SIZE);
    if (pad_len == 0) pad_len = AES_BLOCK_SIZE;

    size_t cipher_len = plaintext.size() + pad_len;
    vector<unsigned char> ciphertext(cipher_len);

    memcpy(ciphertext.data(), plaintext.data(), plaintext.size());
    for (size_t i = plaintext.size(); i < cipher_len; ++i) {
        ciphertext[i] = static_cast<unsigned char>(pad_len);
    }

    AES_CTX ctx;
    AES_EncryptInit(&ctx, key);
    AES_Encrypt(&ctx, ciphertext.data(),
                static_cast<unsigned int>(cipher_len),
                ciphertext.data());
    AES_CTX_Free(&ctx);

    return ciphertext;
}

vector<unsigned char> aes_ecb_decrypt(
    const vector<unsigned char>& ciphertext,
    const unsigned char* key)
{
    if (ciphertext.size() % AES_BLOCK_SIZE != 0) {
        throw runtime_error("Ciphertext length must be multiple of 16");
    }

    vector<unsigned char> plaintext(ciphertext.size());

    AES_CTX ctx;
    AES_DecryptInit(&ctx, key);
    AES_Decrypt(&ctx, ciphertext.data(),
                static_cast<unsigned int>(ciphertext.size()),
                plaintext.data());
    AES_CTX_Free(&ctx);

    if (plaintext.empty()) return plaintext;

    unsigned char pad_len = plaintext.back();
    if (pad_len > 0 && pad_len <= AES_BLOCK_SIZE) {
        plaintext.resize(plaintext.size() - pad_len);
    }

    return plaintext;
}
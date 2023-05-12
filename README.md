# encryptor-

 README file for the RSA key generation and encryption/decryption program:

RSA Key Generation and Encryption/Decryption Program
This program generates RSA public and private keys, and allows the user to encrypt and decrypt messages using those keys.

Features
Generates two random prime numbers p and q
Calculates the modulus n as n = p * q
Calculates Euler's totient function phi(n) as phi(n) = (p - 1) * (q - 1)
Chooses a random number e that is relatively prime to phi(n)
Calculates the modular inverse of e as d, which is the private key
Prints the public key (e, n) and private key (d, n) to the console
Prompts the user to enter a message to encrypt
Encrypts the message using the public key as ciphertext = (message^e) mod n
Prints the encrypted message to the console
Decrypts the message using the private key as decrypted_message = (ciphertext^d) mod n
Prints the decrypted message to the console
Usage
Clone the repository to your local machine
Compile the program using a C++ compiler (e.g. g++)
Run the executable file
Follow the prompts to enter a message to encrypt and to generate public and private keys
The encrypted and decrypted messages will be printed to the console
Requirements
C++ compiler (e.g. g++)
Standard C++ library
Standard math library

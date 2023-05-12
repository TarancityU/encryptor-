#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

// Helper function to check if a number is prime
bool is_prime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

// Helper function to generate a random prime number
int generate_prime(int min_value, int max_value) {
    int prime = rand() % (max_value - min_value + 1) + min_value;
    while (!is_prime(prime)) {
        prime = rand() % (max_value - min_value + 1) + min_value;
    }
    return prime;
}

// Helper function to calculate the greatest common divisor (GCD) of two numbers
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

// Helper function to calculate the modular inverse of a number
int modular_inverse(int a, int m) {
    int m0 = m, t, q;
    int x0 = 0, x1 = 1;

    if (m == 1) {
        return 0;
    }

    while (a > 1) {
        q = a / m;
        t = m;
        m = a % m, a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }

    if (x1 < 0) {
        x1 += m0;
    }

    return x1;
}

// Main function to generate RSA keys and encrypt/decrypt messages
int main() {
    // Set the minimum and maximum values for the prime numbers
    int min_value = 1000;
    int max_value = 10000;

    // Generate two random prime numbers p and q
    srand(time(NULL));
    int p = generate_prime(min_value, max_value);
    int q = generate_prime(min_value, max_value);

    // Calculate n (the modulus)
    int n = p * q;

    // Calculate phi(n) (Euler's totient function)
    int phi_n = (p - 1) * (q - 1);

    // Choose a random number e that is relatively prime to phi(n)
    int e = rand() % (phi_n - 2) + 2;
    while (gcd(e, phi_n) != 1) {
        e = rand() % (phi_n - 2) + 2;
    }

    // Calculate the modular inverse of e (the private key)
    int d = modular_inverse(e, phi_n);

    // Print the public and private keys
    cout << "Public key: (" << e << ", " << n << ")" << endl;
    cout << "Private key: (" << d << ", " << n << ")" << endl;

    // Get a message from the user
    int message;
    cout << "Enter a message to encrypt: ";
    cin >> message;

    // Encrypt the message using the public key
    int ciphertext = (int) pow(message, e) % n;

    // Print the encrypted message
    cout << "Encrypted message: " << ciphertext << endl;

    // Decrypt the message using the private key
    int decrypted_message = (int) pow(ciphertext, d) % n;

    // Print the decrypted message
    cout << "Decrypted message: " << decrypted_message << endl;

    return 0;
}

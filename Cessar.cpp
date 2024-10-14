#include <iostream>
#include <string>

class CaesarCipher {
private:
    int shift;

public:
    
    CaesarCipher(int s) : shift(s % 26) {} 

    std::string encrypt(const std::string& plaintext) {
        std::string encrypted = "";
        for (char ch : plaintext) {
            if (isalpha(ch)) {
                char base = islower(ch) ? 'a' : 'A';
                encrypted += (ch - base + shift) % 26 + base;
            }
            else {
                encrypted += ch; 
            }
        }
        return encrypted;
    }

    std::string decrypt(const std::string& ciphertext) {
        std::string decrypted = "";
        for (char ch : ciphertext) {
            if (isalpha(ch)) {
                char base = islower(ch) ? 'a' : 'A';
                decrypted += (ch - base - shift + 26) % 26 + base;
            }
            else {
                decrypted += ch; 
            }
        }
        return decrypted;
    }
};

int main() {
    std::string text;
    int shift;

    std::cout << "Enter text: ";
    std::getline(std::cin, text);
    std::cout << "Enter shift value: ";
    std::cin >> shift;

    CaesarCipher cipher(shift);
    std::string encrypted = cipher.encrypt(text);
    std::string decrypted = cipher.decrypt(encrypted);

    std::cout << "Encrypted text: " << encrypted << std::endl;
    std::cout << "Decrypted text: " << decrypted << std::endl;

    return 0;
}



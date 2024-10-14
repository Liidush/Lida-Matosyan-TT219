#include <iostream>

class GCD {
private:
    int a;
    int b;

public:
    // Constructor
    GCD(int x, int y) : a(x), b(y) {}

    // Method to compute GCD
    int computeGCD() {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
};

int main() {
    int a = 48;
    int b = 18;

    GCD gcdCalculator(a, b);
    int result = gcdCalculator.computeGCD();

    std::cout << "GCD of " << a << " and " << b << " is: " << result << std::endl;

    return 0;
}
#include <iostream>
using namespace std;

class MathOperations {
public:
    MathOperations(int a, int b) : num1(a), num2(b) {}

    int calculateLCM() {
        return (num1 * num2) / calculateGCD(num1, num2);
    }

private:
    int num1;
    int num2;

    int calculateGCD(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
};

int main() {
    int num1, num2;
    cout << "Input Numbers: ";
    cin >> num1 >> num2;

    MathOperations mathOps(num1, num2);
    int lcm = mathOps.calculateLCM();

    cout << "LCM " << num1 << " and " << num2 << " Numbers " << lcm << endl;

    return 0;
}

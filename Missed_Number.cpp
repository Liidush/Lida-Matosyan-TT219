#include <iostream>
#include <vector>
using namespace std;

class MissingNumberFinder {
public:
    MissingNumberFinder(const vector<int>& nums, int n) : numbers(nums), maxNumber(n) {}

    int findMissingNumber() {

        int expectedSum = (maxNumber * (maxNumber + 1)) / 2;

     
        int actualSum = 0;
        for (int num : numbers) {
            actualSum += num;
        }

        return expectedSum - actualSum;
    }

private:
    vector<int> numbers;
    int maxNumber;
};

int main() {
    vector<int> numbers = { 1, 2, 3, 5 }; 
    int n = 5; 

    MissingNumberFinder finder(numbers, n);
    int missingNumber = finder.findMissingNumber();
    cout << "Missing Number: " << missingNumber << endl;

    return 0;
}

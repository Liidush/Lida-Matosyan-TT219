#include <iostream>
#include <vector>
#include <string>

using namespace std;

string RLECompress(const string& input) {
    string result = "";
    int n = input.length();

    for (int i = 0; i < n; i++) {
        int count = 1;

        while (i < n - 1 && input[i] == input[i + 1]) {
            count++;
            i++;
        }

        result += input[i] + to_string(count);
    }

    return result;
}

void printMatrixWithRLE(const vector<vector<char>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    cout << "Original Matrix:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;

    cout << "Row-wise RLE Compression:" << endl;
    for (int i = 0; i < rows; i++) {
        string row = "";
        for (int j = 0; j < cols; j++) {
            row += matrix[i][j];
        }
        string compressedRow = RLECompress(row);
        cout << "Row " << i + 1 << ": " << compressedRow << endl;
    }

    cout << endl;

    cout << "Column-wise RLE Compression:" << endl;
    for (int j = 0; j < cols; j++) {
        string col = "";
        for (int i = 0; i < rows; i++) {
            col += matrix[i][j];
        }
        string compressedCol = RLECompress(col);
        cout << "Column " << j + 1 << ": " << compressedCol << endl;
    }
}

int main() {
    vector<vector<char>> matrix = {
        {'a', 'a', 'b', 'b', 'b', 'c'},
        {'a', 'a', 'a', 'd', 'e', 'e'},
        {'f', 'f', 'f', 'g', 'g', 'g', 'g'}
    };

    printMatrixWithRLE(matrix);

    return 0;
}

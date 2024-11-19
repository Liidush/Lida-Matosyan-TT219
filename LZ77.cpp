#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct LZ77Tuple {
    int offset, length;
    char next_char;
};

vector<LZ77Tuple> LZ77Compress(const string& input) {
    vector<LZ77Tuple> compressed;
    int i = 0;
    while (i < input.size()) {
        int max_len = 0, offset = 0;
        for (int j = max(0, i - 256); j < i; ++j) {
            int len = 0;
            while (i + len < input.size() && input[j + len] == input[i + len] && len < 15) ++len;
            if (len > max_len) { max_len = len; offset = i - j; }
        }
        if (max_len > 0) {
            compressed.push_back({offset, max_len, input[i + max_len]});
            i += max_len + 1;
        } else {
            compressed.push_back({0, 0, input[i++]});
        }
    }
    return compressed;
}

string LZ77Decompress(const vector<LZ77Tuple>& compressed) {
    string result;
    for (auto& t : compressed) {
        if (t.length > 0) {
            int start = result.size() - t.offset;
            for (int i = 0; i < t.length; ++i) result.push_back(result[start + i]);
            result.push_back(t.next_char);
        } else {
            result.push_back(t.next_char);
        }
    }
    return result;
}

int main() {
    string input = "ABABABABAAAA";
    auto compressed = LZ77Compress(input);
    for (auto& t : compressed) cout << "(" << t.offset << "," << t.length << ",'" << t.next_char << "') ";
    cout << endl;

    string decompressed = LZ77Decompress(compressed);
    cout << "Decompressed: " << decompressed << endl;

    return 0;
}

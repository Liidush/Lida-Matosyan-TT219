#include <iostream>
#include <vector>
#include <string>
#include <tuple>

using namespace std;

using LZ77Tuple = tuple<int, int, string>;

vector<LZ77Tuple> lz77_compress(const string& input) {
    int n = input.size();
    vector<LZ77Tuple> compressed;

    int window_size = 256;
    int lookahead_size = 15;

    int i = 0;
    while (i < n) {
        int match_length = 0;
        int match_offset = 0;

        for (int j = max(0, i - window_size); j < i; ++j) {
            int length = 0;
            while (i + length < n && input[j + length] == input[i + length] && length < lookahead_size) {
                ++length;
            }

            if (length > match_length) {
                match_length = length;
                match_offset = i - j;
            }
        }

        if (match_length > 0) {
            string next_chars = input.substr(i, match_length);
            compressed.push_back(make_tuple(match_offset, match_length, next_chars));
            i += match_length;
        }
        else {
            compressed.push_back(make_tuple(0, 0, string(1, input[i])));
            ++i;
        }
    }

    return compressed;
}

void print_compressed(const vector<LZ77Tuple>& compressed) {
    cout << "Compressed Data (Offset, Length, Next Character):" << endl;

    for (size_t i = 0; i < compressed.size(); ++i) {
        int offset = get<0>(compressed[i]);
        int length = get<1>(compressed[i]);
        string next_chars = get<2>(compressed[i]);

        cout << "  Offset: " << offset
            << ", Length: " << length
            << ", Next Character: '" << (next_chars.empty() ? "None" : next_chars) << "'"
            << endl;
    }
}

int main() {
    string input = "ABCDABCD";
    cout << "Original string: " << input << endl;

    vector<LZ77Tuple> compressed = lz77_compress(input);

    print_compressed(compressed);

    return 0;
}

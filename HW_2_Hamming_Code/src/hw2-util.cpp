#include <string>
#include <vector>
#include "hw2-util.h"

using namespace std;

string binary_8(int n) {
    string result = "";
    for (int i = 0; i < 8; i++) {
        result = static_cast<char>('0' + n % 2) + result;
        n /= 2;
    }
    return result;
}

int from_binary(const string & bits) {
    int result = 0;
    for (char ch : bits) {
        result = result * 2 + ch - '0';
    }
    return result;
}

void to_vector(vector<int> & digits, const string & bits) {
    for (char ch : bits) {
        digits.push_back(ch - '0');
    }
}

string bits_to_string(const vector<int> & v) {
    string result = "";
    for (int n : v) {
        result += static_cast<char>(n + '0');
    }
    return result;
}


int flip(int bit) {
    return (bit + 1) % 2;
}

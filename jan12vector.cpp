#include <iostream> 
#include <string> 
#include <sstream> // for istringstream

using namespace std; 

void print(const vector<int> & v) {
    cout << "[";
    if (v.size() > 0) {
        cout << v[0]; // classic fenceposting approach
        for (int i = 1; i < v.size(); i++) {
            cout << ", " << v[i];
        }
        cout << "]";
    }
}

void to_vector(vector<int>& v, const string& bits) {
    for (char ch: bits) {
        v.push_back(ch - 48); // add 0 or 1 to end of vector (ch either 48 or 49)
    }
}

// doubles each value in vector
// need reference parameter to vector itself and the nested data to actually udpate
void double_all(vector<int>& v) {
    for (int& n : v) {
        n *= 2;
    }
}

// go through vector and turn into string equivalent
string vector_bits_to_string(const vector<int>& v) {
    string result; 
    for (int n : v) {
        result += static_cast<char>(n + 48);
    }
    return result;
}

// 0 <= n<= 256
// post: 8-character string with binary representation of n
    // odd numbers end in 1, even 0
string binary_8(int n) {
    string result;
    for (int i = 0; i < 8; i++) {
        result = static_cast<char> ('0' + n % 2) + result; 
        n /= 2; // since dealing with binary 
    }
    return result;
}

// given string fo bits, turn into int
int from_binary(const string& bits) {
    int result = 0;
    // for (int i = 0; i < bits.size(); i++) {
    //     // do something with bits[i]
    //     result = result * 2 + (bits[i] - '0');
    // }
    for (char ch : bits) {
        result = result * 2 + (ch - '0');
    }
    return result;
}

int main() {
    string bits = binary_8(2008);
    cout << bits << endl;
    cout << from_binary("1101100") << endl;
    vector<int> primes = {2, 3, 5, 7, 11};
    print(primes);
    vector<int> v1;
    to_vector(v1, "11011000");
    cout << endl;
    print(v1);
    cout << endl;
    string res = vector_bits_to_string(v1);
    cout << res << endl;
    double_all(primes);
    print(primes);

}
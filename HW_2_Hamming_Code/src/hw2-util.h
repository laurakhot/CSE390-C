#ifndef HW2_UTIL_H
#define HW2_UTIL_H

#include <string>
#include <vector>

using namespace std;

// pre : 0 <= n < 256
// post: returns an 8-character string with the binary representation of n
string binary_8(int n);

// pre : bits contains a sequence of bits (the characters 0 and 1)
// post: returns the integer equivalent of the binary representation
int from_binary(const string & bits); 

// pre : bits contains a sequence of bits (the characters 0 and 1)
// post: the individual bits are appended to the end of the given vector
void to_vector(vector<int> & digits, const string & bits);

// pre : digits contains a sequence of bits (the values 0 and 1)
// post: returns a string representation of the bits
string bits_to_string(const vector<int> & v);

// pre : bit is 0 or 1
// post: returns the opposite bit
int flip(int bit);

#endif

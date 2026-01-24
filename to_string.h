// a collection of functions that convert from int/double/vector to string

#ifndef TO_STRING_H // considered a constant
#define TO_STRING_H

#include <string>
#include <vector>

using namespace std;

// returns a string version of the given int
string int_to_string(int n);

// returns a string version of the given double
string double_to_string(double n);

// returns a string version of the given vector as a comma-separated,
// bracketed, list
string vector_to_string(const vector<int> & v);

#endif
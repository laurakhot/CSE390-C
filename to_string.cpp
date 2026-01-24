// code for functions that convert from int/double/vector to string
#include <string>
#include <sstream>
#include <vector>
#include "to_string.h"

using namespace std;

// implementation detials 
string int_to_string(int n) {
    ostringstream out; 
    out << n; 
    return out.str();
}

string double_to_string(double n) {
    ostringstream out;
    out << n;
    return out.str();
}

string vector_to_string(const vector<int> & v) {
    ostringstream out;
    out << "[";
    if (v.size() > 0) {
        out << v[0];
        for (int i = 1; i < v.size(); i++) {
            out << ", " << v[i];
        }
    }
    out << "]";
    return out.str();
}
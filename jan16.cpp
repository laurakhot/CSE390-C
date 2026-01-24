// Variation of sample3.cpp that splits off the "to string" functions into a
// separate file.

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "to_string.h" // our own header file (put system includes first then local includes)

using namespace std;

// separate compilation 
// compile main and libraries separately 
// g++ compiles individual file snad links them together to make executable
int main() {
    vector<int> primes = {2, 3, 5, 7, 11};   // constructs vector with values

    cout << "give me an int: ";
    int n1;
    cin >> n1;
    cout << "give me a double: ";
    double n2;
    cin >> n2;
    
    ofstream out1(int_to_string(n1) + ".txt");
    ofstream out2(double_to_string(n2) + ".txt");
    out1 << "primes = " << vector_to_string(primes) << endl;
    primes.push_back(13);
    primes.push_back(17);
    out2 << "primes = " << vector_to_string(primes) << endl;

    return 0;
}
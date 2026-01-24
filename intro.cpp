#include <iostream>
using namespace std; //opening up for use (danger of collision if name something same thing as what is in std namespace)
#include <cmath> // for pow function

int main() {
    count << "Hello, World!" << endl;

    for (int i = 0; i < 10; i++) {
        cout << "Iteration: " << i << "-squared" << i * i << endl; // put things onto output stream
    }

    // factors of 2 - cin
    int n; 
    cout << "give me an int to find the factors of 2 of: "; // insertion operator
    cin >> n; // extraction operator
    cout << "Factors of 2 of " << n << " are: " << endl;
    while (n % 2 == 0) {
        cout << "2 * ";
        n = n / 2;
    }
    cout << n << endl; 
    cout << endl;

    // exponentiation
    int x, y; 
    cout << "give me 2 values to find the exponent of: "; 
    cin >> x >> y;
    cout << "x^y = " << pow(x, y) << endl;
    cout << endl;

    bool isprime(int n) {
        int max = sqrt(n); 
    }

}
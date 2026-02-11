#include <iostream>
#include <string>

struct stuff {
    
};

// void add(node * & p, int value);

// first const is for the stuff object, second const is for the pointer itself
void foo(const stuff * const p) { // pointer being passed by value (copy of the pointer; diff var that stores the same pointer) - if not passing by reference
    p->x = 14; 
    p = nullptr; // resetting the copy of p (not reflected in main)
}

int main() {
    stuff d; 
    stuff * p = &d;

    int x = 35; 
    int & y = x; 
    int *p, p3; 
    p = &x; // p3 is an int 
    (*p)++;

    string s1 = "hello"; 
    string * p2 = &s1; 
    s1[1] = '*'; 
    (*p2)[2] = '-';
}


// y -= x = 2 + 3 * 5
// operator-=(y, operator=(x, operator+(2, operator*(3, 5)))


// cout << "x = " << 2 * 3 << endl; -> expressions ahve higher precedence than insertion operator 
// operator<<(operator<<(operator<<(cout, "x = "), operator*(2, 3)), endl)

// token-based
ifstream input("data.txt"); 
string token; 
int n ;
while (input >> token >> n) { // ignoring whitespace, newlines 
    ...
}

// line-based
string line; 
while(getline(input, line)) { // strema to read from adn where to put result are params of getline
    istringstream data(line); // creating string stream on the line from input file
    while (data >> token) {
        ...;
    }
    ...;
}

ostringstream out; // output string 
out << ...; // using overloaded insertion oeprator to mock java's string concactenation
return out.str();

in n = ...; 
while (n != 0) {
    // n % 10 
    // n = n /10;
}
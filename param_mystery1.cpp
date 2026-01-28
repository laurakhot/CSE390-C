// main's a variable is stored at address 0xaa00
// main's b variable is stored at address 0xbb00
// main's c variable is stored at address 0xcc00
// main's d variable is stored at address 0xdd00
#include <iostream>
using namespace std; 


int parameterMystery1(int a, int& b, int* c) {
    b++;
    a += *c;
    cout << b << " " << *c << " " << a << " " << c << endl;
    c = &a;
    return a - b;
}

int main() {
    int a = 4;
    int b = 8;
    int c = -3;
    int d;

    d = parameterMystery1(a, b, &c);
    parameterMystery1(c, d, &b);
    parameterMystery1(b, a, &d);
    cout << a << " " << b << " " << c << " " << d << endl;

    return 0;
}

// line 1: 9 -3 1 0xcc00


// main
// a -> 4
// b -> 8 
// c -> -3 
// d -> 


// mystery 
// a -> 4
// 

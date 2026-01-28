#include <iostream>
#include <string> 

using namespace std; 

int main() {
    int x = 13; 
    int y = 28; 

    int * p = nullptr;
    cout << "x = " << x << ", y =  " << y << ", p = " << p << endl;
    cout << endl; 

    p = &x; // address of operator (asking for the address of x)
    *p *= 2; // *p follows the pointer to the int its pointing at (deferencing), but still stores pointer - will be different bit of memory every time execute program
    cout << "x = " << x << ", y =  " << y << ", p = " << p << endl;
    cout << endl; 

    int data[4]; //fixed size, contiguous memory
    // int * data; // same type as arr above since arr variable stores pointer 
    cout << data << endl;
    cout << data + 1 << endl; // will add 4 bytes to current address to get next location in memory (address of next int in arr = pointer arithmetic)
    cout << endl;

    p = &y; 
    *p = *p + 10; // int arithmetic
    cout << "x = " << x << ", y =  " << y << ", p = " << p << endl;
    cout << endl; 

    int & a = x; // a is reference to x
    a = a * 3;
    cout << "x = " << x << ", y =  " << y << ", p = " << p << endl;
    cout << endl; 

    p = new int(42); // find memory on heap (dynamic allocation) and uses address of that to set p
    cout << "x = " << x << ", y =  " << y << ", p = " << p << endl;
    cout << endl; 
    delete p;

    // string text = "hello there"; // callign constructor of string class and passing c-style string
    const char * text = "hello there"; // char [] == char * since arr are stored as pointers, string is being stored in read-only part of memory
    cout << text << endl;
    cout << endl;

    string s = text; // now actual string object (conversion via constructor in string class)
    // same things as doing string s(text);
    
    return 0;
}
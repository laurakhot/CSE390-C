#include <iostream> // access to libraries

// using std::cin, std::cout, std::endl // from std namespace

using namespace std; 

// print character n times
void print(int n, char ch='*'); // function defaults declared in function prototype

void swap(int & a, int & b);

void inc2(int & a, int & b);

int main() {
    // int x = 2;
    // double y = 2.2;
    // cout << "give me an int and a double: ";// inserting onto the stream
    // cin >> x >> y; // extracting from the stream
    // cout << "x : " << x << " y: " << y << endl;
    // return 0;

    // print(10, '<');
    // print(10, '=');
    // cout << endl << endl;
    // print(20);
    int x = 10;
    int y = 20;
    cout << "Before swap - x: " << x << " y: " << y << endl;
    swap(x, y);
    cout << "After swap - x: " << x << " y: " << y << endl;
    inc2(x, y);
    cout << "After inc2 - x: " << x << " y: " << y << endl;
    return 0;
}

// edge cases: 
// - give 2 doubles 
// - give a string and dobule (string returns , double isn't processed at all)

// once stream gets into bad state, doesn't do rest of extraction
void print(int n, char ch) {
    for (int i = 0; i < n; i++) {
        cout << ch;
    }
}

// pre: a = a', b = b'
// post: a = a' + 1, b = b' + 1
// proof fails if pass same variable for a and b
void inc2(int & a, int & b) {
    a++;
    b++;
}

// value parameters: copy (regular parameter)
// & -> reference parameter: alias
void swap(int & a, int & b) {
    int temp = a;
    a = b;
    b = temp;
    cout << "a: " << a << " b: " << b << endl;
}
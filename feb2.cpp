#include <string>
#include <iostream>

using namespace std;

class combo {
    public: 
        combo(int initial_value = 0, const string & initial_text = "foo") {
            value = initial_value;
            text = initial_text;
            cout << "in regular constructor" << endl;
        }

        combo(const combo & rhs) {
            value = rhs.value; 
            text = rhs.text;
            cout << "in copy constructor" << endl;
        }
        // destructor
        ~combo() {
            cout << "in destructor for value " << value << endl;
        }

        combo & operator=(const combo & rhs) { // implicit this for lhs
            value = rhs.value; 
            text = rhs.text;
            cout << "in assignment operator" << endl;
            return *this;
        }

        int get_value() const {
            return value;
        }

        const string & get_text() const {
            return text;
        }
    private: 
    int value; 
    string text;
};

int main() {
    combo c1(23, "bar"); 
    combo c2(7); 
    combo c3; 
    cout << "c1: " << c1.get_text() << " " << c1.get_value() << endl;
    cout << "c2: " << c2.get_text() << " " << c2.get_value() << endl;
    cout << "c3: " << c3.get_text() << " " << c3.get_value() << endl;

    cout << "before inner scope" << endl; 
    {
        combo c(12);
    }
    // once exit the inner scope, combo w val 12 is destructured
    cout << "after inner scope" << endl; 

    combo c4 = c1; // this calls a constructor (declaration with assignment calls copy consturcotr)
    // combo c4(c1); -> this is the copy constructor 
    cout << "c4: " << c4.get_text() << " " << c4.get_value() << endl;

    combo c5; // calls regular constructor
    c5 = c2; // calls assignment operator



    return 0;
}
#include <string>
#include <iostream>

using namespace std;

class combo {
    public: 
        combo(int initial_value = 0, const string & initial_text = "foo") {
            value = initial_value;
            text = new string(initial_text); // want to make it heap allocated, don't want to reference string given 
            cout << "in regular constructor" << endl;
        }

        combo(const combo & rhs) { // creating new object so much make new stirng
            value = rhs.value; 
            text = new string (*rhs.text);
            cout << "in copy constructor" << endl;
        }
        // destructor
        ~combo() {
            delete text; // freeing up sapce from heap allocated string
            cout << "in destructor for value " << value << endl;
        }

        // x = x; -> don't want behavior if assigning to itself

        combo & operator=(const combo & rhs) { // implicit this for lhs // overwriting values for current object for might now want to create completely new string obejct
            if (this != &rhs) {
                value = rhs.value; 
                // text = rhs.text; // issue: not freeing up space from old text and pointer uses other objects string
                // delete text; 
                // text = new string(*rhs.text); // this makes deep copy
                *text = *rhs.text; // not aliasing, calling string assignment (s1 = s2 -> keeps objects separate)
            }
            cout << "in assignment operator" << endl;
            return *this;
        }

        int get_value() const {
            return value;
        }

        const string & get_text() const {
            return *text;
        }
    private: 
    int value; 
    string * text;
};

void print(const vector<combo> & v) {
    cout << "in for each loop" << endl;
    for (const combo & c : v) {
        cout << "combo with value " << c.get_value() << " and text " << c.get_text() << endl;
    }
}

int main() {
    combo c(42, "hello");
    cout << "setting up vector" << endl;
    vector<combo> v;
    v.reserve(4); // tells how many items you want in advance
    v.emplace_back(3, "bar");
    v.emplace_back(5, "hello");
    v.emplace_back(7, "mumble");
    v.emplace_back(c.get_value(), c.get_text());
    print(v);
    return 0;
}
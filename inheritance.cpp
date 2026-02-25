// class examples of using initializer lists and inheritance

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std; 

class foo {
    public: 
    // initializer list
        foo(ostream & o, const string & the_id, int n) 
            : out(o), id(the_id), y(x - 1), z(x + 1), x(2 * n) {
            // out = o; // streams don't overwrite the assigment operator, can't make a copy
            // x = 2 * n; 
            // y = 2 * n - 1; 
            // z = 2 * n + 1;
        }
        void print() const { // can be const since out is reference member var (doesn't impact the object's stte sine can think of referene as not prtaining to obect itself)
            out << "id : " << id << ", x = " << x << " , y = " << y << " , z = " << z << endl;
        }
    private: 
        ostream & out; // defining the kind of output stream you want (file or something else)
        const string id; 
        int x, y, z;
};

class person {
    public: 
        person(string ssn, string name) : 
            ssn(ssn), name(name) {
            // nothing else to do
        }

        virtual string to_string() const {
            ostringstream out; 
            out << "ssn : " << ssn << ", name : " << name;
            return out.str();
        }

    protected: 
        string ssn; 
        string name;
};

class student : public person {
    public: 
        student(string ssn, string name, double gpa) :
            person(ssn, name), gpa(gpa) { // must call base class constructor with initialization list
                // nothing else to do
            }

        string to_string() const {
            ostringstream out; 
            out << person::to_string() << ", gpa = " << gpa; 
            return out.str();
        }
    private: 
        double gpa; 
};


int main() {
    foo f(cout, "784392", 5);
    f.print(); 
    cout << endl;

    person p1("555-23-2344", "Fred Smith");
    cout << p1.to_string() << endl;

    student s1("342-89-7384", "Susan Hayward", 3.95);
    cout << s1.to_string() << endl;
    cout << endl;

    person & p2 = s1;
    cout << p2.to_string() << endl; // doesn't print gpa 

    // polymorphism (many forms) -> use student to_string if objec tis tudent type vs person if person type (Java always does this)

    // slicing: BAD (only allocated space for 2 member vars since that is type vector decalred as so sliced off last member var for student's gpa)
    // fix this with pointers
    vector<person> v; 
    v.push_back(p1); 
    v.push_back(p2); 
    for (const person & p : v) {
        cout << p.to_string() << endl;
    }
    return 0; 
}
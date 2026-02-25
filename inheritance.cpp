// is-a: student is a person (subclass is a superclass)
// has-a: person has an arm (composition -> member function/ var)
// has-a: person has a lawyer (association) -> not part of object itself
    // relates to the reference to stream in foo class (associating with that obj)
    // member function can be const and still change the assoication

// class examples of using initializer lists and inheritance

// always use pointers with inheritance, otherwise get slicing
// always introduce a virtual destructor in base class for inheritance  

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

        // creates new object
        person (const person & rhs) {
            ssn = rhs.ssn;
            name = rhs.name;
        }

        // reassigns an existing object 
        person & operator=(const person & rhs) {
            if (this != &rhs) {
                ssn = rhs.ssn;
                name = rhs.name;
            }
            return *this; 
        }

        virtual ~person() {
            // nothing extra to do but need this to make it virtual so dashes string is always destructed (otherwise memory leak)
        }

        virtual string to_string() const {
            ostringstream out; 
            out << "ssn : " << ssn << ", name: " << name;
            return out.str();
        }

    protected: 
        string ssn; 
        string name;
};

class student : public person {
    public: 
        student(string ssn, string name, double gpa) :
            person(ssn, name), gpa(gpa), dashes(person::to_string().size(), '-') { // must call base class constructor with initialization list
                // nothing else to do
            }
        student(const student & rhs) 
            : person(rhs), gpa(rhs.gpa), dashes(rhs.dashes) {
            // nothing left to do
        }

        student & operator=(const student & rhs) {
            if (this != &rhs) {
                person::operator=(rhs); // call base class assignment operator to assign base class part of student object
                gpa = rhs.gpa;
                dashes = rhs.dashes;
            }
            return *this;
        }

        string to_string() const {
            ostringstream out; 
            out << person::to_string() << endl << dashes << endl << "gpa = " << gpa << endl; 
            return out.str();
        }
    private: 
        double gpa; 
        string dashes;
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
    cout << "first vector: " << endl;
    vector<person> v; 
    v.push_back(p1); 
    v.push_back(s1); 
    for (const person & p : v) {
        cout << p.to_string() << endl;
    }

    cout << "second vector: " << endl;
    vector<person *> v2; 
    v2.push_back(&p1); 
    v2.push_back(&s1); 
    for (const person * p : v2) {
        cout << p->to_string() << endl;
    }

    person * s2 = new student("234-29-3943", "Bill Gates", 3.5);
    cout << s2->to_string() << endl; // will show gpa since to_string is virtual 
    // cout << endl;
    delete s2;

    person p3(p1); 
    cout << p3.to_string() << endl;
    person p4("234-32-333", "Joe Biden"); 
    p3 = p4; 
    cout << p3.to_string() << endl; 
    cout << p4.to_string() << endl;
    cout << endl;

    student s3(s1); 
    cout << s3.to_string() << endl;
    student s4("234-32-33", "Drake", 4.0); 
    s3= s4; 
    cout << s3.to_string() << endl;
    cout << s4.to_string() << endl;

    person p5(s1); // will call person's class copy constructor (only copies parts of student object that person has -> kind of like slicing)
    cout << p5.to_string() << endl;

    // // will produce errors
    // student s5(p1); 
    // cout << s5.to_string() << endl;

    return 0; 
}
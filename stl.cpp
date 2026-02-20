#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <sstream>

using namespace std;


// returns a string version of the given vector as a comma-separated,
// bracketed, list
string vector_to_string(const vector<int> & v) {
    ostringstream out;
    out << "[";
    if (v.size() > 0) {
        out << v[0];
        for (int i = 1; i < v.size(); i++) {
            out << ", " << v[i];
        }
    }
    out << "]";
    return out.str();
}

int main() {
    vector<int> v {9, -8, 13, 9, 6, 12, 42, 17, -8, 200};
    cout << vector_to_string(v) << endl;
    vector<int> v2 {12, 7, 15}; 
    cout << (v2 < v) << endl; // comapres first elements and returns val (will keep looking at elements until finds diff or returns smaller one if diff never found)

    // vector<int>::iterator itr; // to describe an itr over a vecto
    auto itr = v.begin();
    *(itr + 5) = 35; // moving itr forward by 5 indices // overriding val in vector
    cout << *itr << endl;
    itr = v.end(); 
    itr--;
    cout << *itr << endl; // outputs last val of vector
    cout << vector_to_string(v) << endl;

    // size of vector 
    cout << "size = " << v.size() << endl;
    cout << "size also = " << v.end() - v.begin() << endl; // only works for vectors
    // print out midpoint
    cout << *(v.begin() + (v.end() - v.begin()) / 2) << endl;

    // auto x = 3; // inferences type (variables are still of a type just developer doesn't need to specify)
    // auto z; // this is error since has no clue to type

    // insert a -1 in front of every even # (for loop with iterator)
    // for (vector<int>::iterator itr = v.begin())
    for (auto itr = v.begin(); itr != v.end(); itr++) {
        // do something with *itr
        if (*itr % 2 == 0) {
            itr = v.insert(itr, -1); // insert is member funcction of sructure; iterator is stale after update structure so insert returns new iterator to thing that just inserted
            itr++; // to avoid infinite loop since will increment to even value again and continue inserting -1 in front of it infinitely
        }
    }
    cout << vector_to_string(v) << endl;

    // print values in reverse order 
    // for (auto itr = v.end() - 1; itr >= v.begin(); itr--) {
    //     cout << *itr << endl;
    // }

    // more general approach (would work on set)
    auto itr2 = v.end();  
    while (itr2 != v.begin()) { // also checks if empty strucutre (then beginning and end are same)
        itr2--; // positions to last element onto structure 
        cout << *itr2 << endl;
    }

    // add some multiple fo 3 and then loop to remove all multiplesof 3
    v.push_back(30); 
    v.push_back(18); 
    v.push_back(3); 
    cout << vector_to_string(v) << endl; 
    for (auto itr = v.begin(); itr != v.end(); itr++) {
        if (*itr % 3 == 0) {
            itr = v.erase(itr); // can't rely on value iterator have if changing structure (resets to spot where just deleted something)
            itr--; // to prevent skipping value when increment since setting to next val after deletion (could be problematic if moving itr off first val of structure)
        } 
    }
    cout << vector_to_string(v) << endl; 

    auto itr3 = v.begin(); 
    while (itr3 != v.end()) {
        if (*itr3 % 3 == 0) {
            itr3 = v.erase(itr3);
        } else {
            itr3++;
        }
    }
    return 0;
}
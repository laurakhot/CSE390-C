#include <iostream> 
#include <string>
#include <set>
#include <fstream> 
#include <map>
#include <sstream>


using namespace std;

ostream & operator<<(ostream & out, set<string> s) {
    cout << "["; 
    // set<string>::iterator itr;
    if (!s.empty()) {
        auto itr = s.begin(); 
        cout << *itr; 
        itr++;
        while (itr != s.end()) {
            cout << ", " << *itr; 
            itr++;
        }
    }
    cout << "]";
    return out;
}

// reading all words in file and counting how many rimes each word occurs.
void example1() {
    map<string, int> count; 
    ifstream input("moby.txt"); 
    string word; 
    while (input >> word) {
        // if (count.count(word) == 0) {
        //     count.insert(pair(word, 0));
        // }
        // // (*count.find(word)).second ++;
        // count.find(word)->second ++;
        count[word]++;
    }
    int min; 
    cout << "minimum number of occurences? "; 
    cin >> min; 
    // for (auto itr = count.begin(); itr != count.end(); itr++) {
    //     if (itr->second >= min) {
    //         cout << itr->second << "\t" << itr->first << endl;
    //     }
    // }
    for (const auto & p : count) {
        if (p.second >= min) {
            cout << p.second << "\t" << p.first << endl;
        }
    }
    cout << endl;
}

// Pairs of lines (names and sequeunces of course abbreviations). 
// Given a class, build a string of student names in that class
void example2() {
    map<string, string> courses; 
    ifstream input("stl2.txt"); 
    string name; 
    while (getline(input, name)) { // assuming file structure is not corrupted
        string text; 
        getline(input, text);
        istringstream data(text); 
        string course; 
        while (data >> course) {
            courses[course] += name + ".";
        }
    }
    for (const auto & p : courses) {
        cout << p.first << " maps to " << p.second << endl;
    }
    cout << endl;
}

// variation of example 2 where set keeps track of names of students in the course instead of string
void example3() {
    map<string, set<string>> courses; 
    ifstream input("stl2.txt"); 
    string name; 
    while (getline(input, name)) { // assuming file structure is not corrupted
        string text; 
        getline(input, text);
        istringstream data(text); 
        string course; 
        while (data >> course) {
            courses[course].insert(name);
        }
    }
    for (const auto & p : courses) {
        cout << p.first << " maps to " << p.second << endl; // overrode insertion oeprator for set of string earlier
    }
    cout << endl;

    // remove any course name that begins with c
    // for (auto itr = courses.begin(); itr != courses.end(); itr++) {
    //     if (itr->first[0] == 'c') {
    //         itr = courses.erase(itr);
    //     }
    // } -> want the while loop version of this that either does erase of ++ otherwise will get segmentaiton fault
    for (const auto & p : courses) {
        cout << p.first << " maps to " << p.second << endl; // overrode insertion oeprator for set of string earlier
    }
    cout << endl;
}

int main() {
    set<string> s1 {"four", "score", "play", "around"};
    set<string> s2;
    cout << s1 << endl;
    cout << s2 << endl;
    // example2();
    example3();
    return 0;
}
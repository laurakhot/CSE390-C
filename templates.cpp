#include <iostream>
#include <string> 
#include <vector> 
#include <set>
#include <cmath> 
#include <sstream>

using namespace std;
/*
void print_double(int n) {
    cout << 2 * n << endl;
}

void print_double(double n) {
    cout << 2 * n << endl;
}
*/
template<typename T> // means templating the function
// this type needs plus and overloaded insertion oeprator 
void print_double(T n) {
    cout << n + n << endl;
}

template<typename E>
// E needs to have less than, cop constructor, assignment operator
// if tracking max idx instead just need less that comparison
E find_max(const vector<E> & v) {
    if (v.size() == 0) {
        throw runtime_error("empty vector");
    } else {
        // E max = v[0]; 
        int max_idx = 0;
        for (int i = 1; i < v.size(); i++) {
            if (v[max_idx] < v[i]) { // more likely to have less that overloaded operator
                max_idx = i;
            }
        }
        return v[max_idx];
    }
}

template<typename T>
// structure needs to have a begin & end 
// structure's element type must have overriden insertion operator to put onto output stream
string to_string(T data) {
    ostringstream out; 
    out << "["; 
    auto itr = data.begin();
    if (itr != data.end()) {
        out << *itr;
        ++itr;
        while (itr != data.end()) {
            out << ", " << *itr;
            ++itr;
        }
    }
    out << "]";
    return out.str();
}

struct point {
    point(int x, int y) 
        : x(x), y(y) {
        // nothing else to do
    }
    int x, y;
};

point operator+(const point & lhs, const point & rhs) {
    return point(lhs.x + rhs.x, lhs.y + rhs.y);
}

ostream & operator<<(ostream & out, const point & rhs) { 
    out << "(" << rhs.x << ", " << rhs.y << ")";
    return out;
}

// returns the point's distance from the origin 
// sqrt(x ^ 2 + y * 2)
double distance(const point & p) {
    return sqrt(p.x * p.x + p.y * p.y);
}

bool operator<(const point & lhs, const point & rhs) {
    return distance(lhs) < distance(rhs);
}

template<typename T1, typename T2, typename T3>
struct triple {
    triple(T1 a, T2 b, T3 c)
        : first(a), second(b), third(c) {
        // nothing else to do
    }
    T1 first; 
    T2 second; 
    T3 third;

    // void f() {
    //     cout << 2 * first << endl;
    // }
};

int main() {
    print_double(18); 
    print_double(17.4); // prints 34 in int version
    // print_double("hello"); // const char*
    print_double(string("hello")); // string overload + not * operator

    vector<int> v1 {3, 18, 9, 24, 7, -8, 203, 15, 42};
    cout << find_max(v1) << endl; // 203

    vector<double> v2 {3.14, 18.2, 9.5, 24.7, 7.3, -8.1, 203.9, 15.0, 42.2};
    cout << find_max(v2) << endl;

    vector<string> v3 {"mouse", "cat", "elephant", "dog", "bird", "years"};
    cout << find_max(v3) << endl;


    set<int> s1 {3, 8, 19, 7, 42, 3, 3, 3}; 
    set<string> s2 {"four", "score", "board", "about"};
    cout << to_string(vector<int>{4, 8, 15, 16, 23, 42}) << endl;
    cout << to_string(s1) << endl;
    cout << to_string(s2) << endl;

    vector<point> v5 {point(1, 2), point(3, 4), point(5, 6)};
    cout << find_max(v5) << endl;
    cout << to_string(v5) << endl;

    triple<string, int, double> t("hello", 18, 45.2);
    cout << t.first << " " << t.second << " " << t.third << endl; // know that things in teh triple have overloeaded insertion operator
}


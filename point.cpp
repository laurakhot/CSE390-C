#include <string>
#include <iostream>
#include <sstream>
#include <cmath>
#include "point.h"

using namespace std; // would work without this since included in header file
// can;t define class more that once so use scope resolution operator to show that inside point class

    // Java: fields 
    // C++: instance variables 
point::point(int initial_x, int initial_y) {
    set_location(initial_x, initial_y); 
    cout << "constructing" << to_string() << endl;
}

// always uses ostringstream
string point::to_string() const {
    ostringstream output;
    output << "(" << x << " , " << y << ")";
    return output.str();
}

void point::translate(int dx, int dy) { // mutator
    x = x + dx;
    y = y + dy;
}

double point::distance_from_origin() const {
    return sqrt(x*x + y*y);
}

int point::get_x() const {
    return x;
}

int point::get_y() const {
    return y;
}

void point::set_location(int new_x, int new_y) { // mutator
    x = new_x;
    y = new_y;
}

// cout << p => func(count, p)
// free standing function since don't have access to ostream 
ostream & operator<<(ostream & out, const point & p) {
    out << p.to_string();
    return out;
}

bool operator<(const point & lhs, const point & rhs) {
    return lhs.distance_from_origin() < rhs.distance_from_origin();
}

bool operator>(const point & lhs, const point & rhs) {
    return !(lhs<rhs);
}

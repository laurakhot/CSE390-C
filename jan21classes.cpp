#include <iostream>
#include <sstream>
#include <cmath> 
#include <string>
#include <vector>

using namespace std; 

class point {
public: // public first then private
// Java: fields 
// C++: instance variables 
    point(int initial_x = 0, int initial_y = 0) {
        x = initial_x; 
        y = initial_y;
        cout << "constructing" << to_string() << endl;
    }

    // return type indicates that is member funciton, not constructor
    void translate(int dx, int dy) { // mutator
        x = x + dx;
        y = y + dy;
    }

    double distance_from_origin() const {
        return sqrt(x*x + y*y);
    }

    // always uses ostringstream
    string to_string() const {
        ostringstream output;
        output << "(" << x << " , " << y << ")";
        return output.str();
    }

    int get_x() const {
        return x;
    }

    int get_y() const {
        return y;
    }

    void set_location(int new_x, int new_y) { // mutator
        x = new_x;
        y = new_y;
    }

private: 
    int x, y;
}; 

// struct point {
//     int x, y;
// };

int count_equal(const vector<point> & points) {
    int count = 0;
    for (const point & p: points) { // this also needs to be a const since the vector is a const so can't modify, can't throw away the "constness"
        if (p.get_x()== p.get_y()) {
            count++;
        }
    }
    return count;
}

int main() {
    point p1; // default assignment of x, y to 0, 0
    point p2; 
    point p3(13, 5);
    p2.set_location(3, 18);
    // p2.x = 3; 
    // p2.y = 18; 

    cout << "p1 = " << p1.to_string() << endl;
    cout << "p2 = (" << p2.get_x() << " , " << p2.get_y() << ")" << endl;
    cout << "p3 = (" << p3.get_x() << " , " << p3.get_y() << ")" << endl;

    p1.translate(3, 18);

    cout << "now p1 = " << p1.to_string() << endl;

    cout << "p1 distance from origin = " << p1.distance_from_origin() << endl;
    cout << "p2 distance from origin = " << p2.distance_from_origin() << endl;
    cout << "p3 distance from origin = " << p3.distance_from_origin() << endl;

    vector<point> v; // stack allocated
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j<= 3; j++) {
            v.push_back(point(i, j));
        }
    }

    cout << count_equal(v) << endl; // count how many points have same x and y

    cout << endl; 

    return 0;
}
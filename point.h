#ifndef MY_POINT_H
#define MY_POINT_H
#include <string>

using namespace std;

// this header file like Java interface (not revealing implementation)
class point { // if wa struct would work same
    public: 
    point (int init_x = 0, int init_y = 0);

    // return type indicates that is member funciton, not constructor
    void translate(int dx, int dy);

    double distance_from_origin() const; // const part of function signature

    // always uses ostringstream
    string to_string() const;

    int get_x() const;

    int get_y() const;

    void set_location(int new_x, int new_y);

private: 
    int x, y; // compiler needs instance variables since stack allocated object (despit this being implementation details) 
};

ostream & operator<<(ostream & out, const point & p);

bool operator<(const point & lhs, const point & rhs);

bool operator>(const point & lhs, const point & rhs);

#endif
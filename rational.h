#ifndef _RATIONAL_H
#define _RATIONAL_H

#include <iostream>

using namespace std; 

// data invariant (relationships that always hold): 
// denom > 0
// gcd(numerator , denomiator) = 1 (both have been simplified as much as possible)
class rational {
    public: 
        rational(int num = 0, int denom = 1);

        int get_numerator() const;

        int get_denominator() const;

        rational & operator-=(const rational & rhs);

        // ++ r -> increments by 1 and returns reference to new value 
        // pre-increment
        rational & operator++();
        // r ++ -> increment but returns reference to og value 
        // post-increment
        rational operator++(int dummy);
    private: 
        int numerator; 
        int denominator; 
        void reduce();
        void fix_signs();
};

// r1 -= r2
// r1.operator-=(r2) -> shows that needs to be member function
ostream & operator<<(ostream & out, const rational & r);

rational operator-(const rational & lhs, const rational & rhs);

bool operator==(const rational & lhs, const rational & rhs);

bool operator!=(const rational & lhs, const rational & rhs);

bool operator<=(const rational & lhs, const rational & rhs);

bool operator>(const rational & lhs, const rational & rhs);

#endif
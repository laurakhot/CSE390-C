#include <iostream>
#include "rational.h"

using namespace std; 

// data invariant (relationships that always hold): 
// denom > 0
// gcd(numerator , denomiator) = 1 (both have been simplified as much as possible)

rational::rational(int num, int denom) { // can't repeat default
    if (denom == 0) {
        throw invalid_argument("denominator must not be 0");
    }
    numerator = num; 
    denominator = denom;
    fix_signs();
    reduce(); // use greatest common divisor
}

int rational:: get_numerator() const {
    return numerator;
}

int rational::get_denominator() const {
    return denominator;
}

rational & rational::operator-=(const rational & rhs) { // want rational as return type so can assign this obejct to a var like r4 = r1 -= r2
    // n1 / d1 - n2 / d2 
    // want common denom d1 * d2
    // (n1 * d2 - n2 * d1)/(d1*d2)
    numerator = numerator * rhs.denominator - rhs.numerator * denominator;
    denominator *= rhs.denominator;
    reduce();
    return *this; // can change assignment so need to return implicit first apram
}

// ++ r -> increments by 1 and returns reference to new value 
// pre-increment
rational & rational::operator++() {
    numerator += denominator; 
    return *this;
}
// r ++ -> increment but returns reference to og value 
// post-increment
rational rational::operator++(int dummy) { // dummy value to differentiate between postfix and prefix ++ operator 
    rational copy(*this);
    numerator += denominator;
    return copy;
} // if this was a rational reference return type, would be referncing local var copy that is popped off the stack (dangerous)


void rational::reduce() {
    int d = gcd(numerator, denominator); 
    numerator /= d;
    denominator /= d;
}

void rational::fix_signs() {
    if (denominator < 0) { // multiplying by -1/-1
        denominator = -denominator; 
        numerator = - numerator;
    }
}

// end of member functions: 

// r1 -= r2
// r1.operator-=(r2) -> shows that needs to be member function
int gcd(int a, int b) {
    a = abs(a);
    b = abs(b);

    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

ostream & operator<<(ostream & out, const rational & r) {
    out << r.get_numerator(); 
    if (r.get_denominator() != 1) {
        out  << "/" << r.get_denominator();
    }
    return out;
}

rational operator-(const rational & lhs, const rational & rhs) {
    // rational result = lhs;
    rational result(lhs); // same behavior as line above but w copy constructor 
    result -= rhs; 
    return result;
}

bool operator==(const rational & lhs, const rational & rhs) {
    return (lhs - rhs).get_numerator() == 0;
}

bool operator!=(const rational & lhs, const rational & rhs) {
    return !(lhs == rhs);
}

bool operator<=(const rational & lhs, const rational & rhs) {
    return (lhs - rhs).get_numerator() <= 0;
}

bool operator>(const rational & lhs, const rational & rhs) {
    return !(lhs <= rhs);
}



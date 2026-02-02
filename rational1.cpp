#include <iostream>
#include <string> 

using namespace std; 

// data invariant (relationships that always hold): 
// denom > 0
// gcd(numerator , denomiator) = 1 (both have been simplified as much as possible)
class rational {
    public: 
        rational(int num = 0, int denom = 1) {
            if (denom == 0) {
                throw invalid_argument("denominator must not be 0");
            }
            numerator = num; 
            denominator = denom;
            fix_signs();
            reduce(); // use greatest common divisor
        }

        int get_numerator() const {
            return numerator;
        }

        int get_denominator() const {
            return denominator;
        }

        rational & operator-=(const rational & rhs) { // want rational as return type so can assign this obejct to a var like r4 = r1 -= r2
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
        rational & operator++() {
            numerator += denominator; 
            return *this;
        }
        // r ++ -> increment but returns reference to og value 
        // post-increment
        rational operator++(int dummy) { // dummy value to differentiate between postfix and prefix ++ operator 
            rational copy(*this);
            numerator += denominator;
            return copy;
        } // if this was a rational reference return type, would be referncing local var copy that is popped off the stack (dangerous)
    private: 
        int numerator; 
        int denominator; 

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

        void reduce() {
            int d = gcd(numerator, denominator); 
            numerator /= d;
            denominator /= d;
        }

        void fix_signs() {
            if (denominator < 0) { // multiplying by -1/-1
                denominator = -denominator; 
                numerator = - numerator;
            }
        }
};

// r1 -= r2
// r1.operator-=(r2) -> shows that needs to be member function

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


int main() {
    rational r1(3, 4), r2(5), r3;
    rational r4(6, -16);

    cout << "r1 = " << r1 << " , r2 = " << r2 << " , r3 = " << r3 << endl;
    cout << r4 << endl;

    cout << "r1 = " << r1 << ", r2 = " << r2 << ", r3 = " << r3 << endl;
    r1 -= r4;
    r2 -= r4;
    r3 -= r4;
    cout << "r1 = " << r1 << ", r2 = " << r2 << ", r3 = " << r3 << endl;
    cout << endl;

    int x = 3, y = 7; 
    y = x -= 1;
    //operator=(y, operator-=(x, 1))
    cout << "x = " << x << ", y =" << y << endl;
    cout << endl;
    (x-=2)++;
    cout << "x = " << x << ", y =" << y << endl;
    cout << endl;

    r3 = r1 -= r2;
    //operator=(r3, operator-=(r1, r2))
    cout << "r1 = " << r1 << ", r2 = " << r2 << ", r3 = " << r3 << endl;
    cout << endl;

    r4 = r1 - r3;
    cout << "now r4 = " << r4 << endl;
    cout << endl;

    // rational r5(1, 0);
    // cout << r5 << endl;

    rational r5(r3);
    if (r5 == r3) {
        cout << "r5 and r3 equal" << endl;
    } else {
        cout << "r5 and r3 not equal" << endl;
    }
    if (r1 == r2) {
        cout << "r1 and r2 equal" << endl;
    } else {
        cout << "r1 and r2 not equal" << endl;
    }
    cout << endl;

    cout << "r1 = " << r1 << endl;
    rational r6 = r1++; // must be member function since changing state
    // operator++(r1);
    cout << "r1 = " << r1 << " r6 = " << r6 << endl;

    cout << "r1 = " << r1 << ", r2 = " << r2 << ", r3 = " << r3 << endl;
    cout << "r1 <= r2  = " << (r1 <= r2) << endl;
    cout << "r1 <= r3  = " << (r1 <= r3) << endl;
    cout << "r2 <= r3  = " << (r2 <= r3) << endl;
    cout << endl;
}
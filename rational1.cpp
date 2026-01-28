#include <iostream>
#include <string> 

using namespace std; 

class rational {
    public: 
        rational(int num = 0, int denom = 1) {
            numerator = num; 
            denominator = denom;
            if (denominator < 0) { // multiplying by -1/-1
                denominator = -denominator; 
                numerator = - numerator;
            }
            reduce(); // use greatest common divisor
        }

        int get_numerator() const {
            return numerator;
        }

        int get_denominator() const {
            return denominator;
        }

        rational & operator-=(const rational & rhs) {
            // n1 / d1 - n2 / d2 
            // want common denom d1 * d2
            // (n1 * d2 - n2 * d1)/(d1*d2)
            numerator = numerator * rhs.denominator - rhs.numerator * denominator;
            denominator *= rhs.denominator;
            reduce();
            return *this; // can change assignment so need to return implicit first apram
        }
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

int main() {
    rational r1(3, 4), r2(5), r3;
    rational r4(6, -16);

    cout << "r1 = " << r1 << " , r2 = " << r2 << " , r3 = " << r3 << endl;
    cout << r4 << endl;
}
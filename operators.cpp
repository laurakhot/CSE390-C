#include <iostream> 
using namespace std;

int main() {
    int x, y; 
    y = 3 - 2 - 1;
    // operator=(y, opertor-(operator-(3, 2), 1));
    x = 8 - 2 * 3 + 4/5 + 2;
    // operator=(x, operator+(operator+(operator-(8, operator*(2, 3)), operator/(4, 5)), 2))
    x = y = 2 + 3;
    // operator=(x, operator=(y, operator+(2, 3)))
    x = 7 + 2 * x;
    // operator=(x, operator+(7, operator*(2, x)))
    y += x + 3;
    // operator=(y, operator+(x, 3))
    cout << x << " " << y << endl;
    // operator<<(operator<<(operator<<(operator<<(cout, x), " "), y), endl)

    bool b = y == 8 + x++;
    // operator=(operator==(y, operator+(8, operator++(x))))
    cout << "x = " << x << ", y = " << y << " , b = " << endl;
    return 0;
}
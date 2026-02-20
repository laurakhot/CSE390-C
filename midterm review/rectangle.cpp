#include <string>
#include <sstream> 
#include <iostream>
 
using namespace std;

class rectangle {
    public: 
        rectangle(const double & w, const double & h) {
            width = w; 
            height = h; 
        }

        string to_string() const {
            ostringstream out; 
            out << width << "x" << height; 
            return out.str(); 
        }

        double area() const {
            return width * height; 
        }

        void scale(const double & n) {
            width *= n; 
            height *= n; 
        }
    private: 
        double width, height; 
};

int main() {
    rectangle r1(4.2, 5.3);
    rectangle r2(10.4, 300);
    cout << "r1 = " << r1.to_string() << ", area = " << r1.area() << endl;
    cout << "r2 = " << r2.to_string() << ", area = " << r2.area() << endl;
    r1.scale(2.3);
    r2.scale(3);
    cout << "r1 scaled = " << r1.to_string() << endl;
    cout << "r2 scaled = " << r2.to_string() << endl;
}
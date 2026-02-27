#include <ostream>
#include <iostream>
using namespace std; 

class shape {
    public: 
        // virtual void print(ostream & out) const = 0;
        shape(const string & name) 
            : name(name) {}
        virtual double area() const = 0;
        virtual ~shape() {}

        void print(ostream & out) const {
            out << name << " of area " << area();
        }
    private: 
        string name;
};

class rectangle : public shape {
    public:
        rectangle(double length, double width)
            : shape("rectangle"), length(length), width(width) {

        }

        double area() const {
            return length * width;
        }

        // void print(ostream & out) const {
        //     out << "rectanlge of area " << area();
        // }

    private:
        double length;
        double width;
};

class square : public shape {
    public: 
        square(double length)
            : shape("square"), length(length) {
        }
        double area() const {
            return length * length;
        }

        // void print(ostream & out) const {
        //     out << "square of area " << area();
        // }
    private: 
        double length;
};

class circle : public shape {
    public: 
        circle(double radius)
            : shape("circle"), radius(radius){

        }

        double area() const {
            return M_PI * radius * radius;
        }

        // void print(ostream & out) const {
        //     out << "circle of area " << area();
        // }
    private: 
        double radius;
};

ostream & operator<<(ostream & out, const shape & rhs) {
    rhs.print(out);
    return out;
}

bool compare(const shape * lhs, const shape * rhs) {
    return lhs->area() < rhs->area();
}

// bool operator<(const shape * & lhs, const shape * & rhs) {
//     return lhs.area() < rhs.area();
// }

int main() {
    vector<shape *> shapes = {new square(12), new rectangle(15, 13.2), new circle(8.4), new circle(1.5), new square(8.7), new rectangle(7.2, 3.2), new square(2.4), new circle(3.7), new circle(7.9)};

    for (auto p : shapes) {
        cout << *p << endl;
    }
    cout << endl;

    sort(shapes.begin(), shapes.end(), compare);
    for (auto p : shapes) {
        cout << *p << endl;
    }
    for (auto p : shapes ) {
        delete p;
    }

    return 0;
}
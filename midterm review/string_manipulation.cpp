
#include <iostream>
#include <sstream> 
#include <string>

using namespace std;

string underline(ifstream & input) {
    // ostringstream out; 
    string line; 
    while (getline(input, line)) {
        if (line.empty() || line[0] != '.') {
            cout << line << endl;
        } else {
            cout << line.substr(1) << endl;
            for (int i; i < line.size() - 1; i++) {
                cout << '-';
            }
            cout << endl;
        }
    }
    return out.str();
}

int main() {
    ifstream input("underline.txt");
    underline(input);
}
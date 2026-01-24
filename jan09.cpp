#include <iostream> 
#include <string> 
#include <sstream> // for istringstream

using namespace std; 

// name = "Khotemlyansky, Laura V."  --> Laura. V. Khotemlyansky
string rearrange(const string& text) {
    int index = text.find(", ");
    return text.substr(index + 2) + " " + text.substr(0, index);

}

// creates compressed version of stirng
// "    this      is      text" => "this is text"
// if it was stream, could extract tokens (use istringstream)
// fencepost loop (begin and end with no space) -> intialize first word out side loop
string fix(const string& text) {
    istringstream input(text); 
    string word;
    string result;
    if (input >> word) { // check if first word exists 
        result = word; 
        while (input >> word) { // while can extract word from input stream (stops loop once extraction fails)
            result += " " + word;
        }
    }
    return result;


}

int main() {
    cout << rearrange("Khotemlyansky, Laura V.") << endl;

    cout << "    this      is      text" << endl;
    cout << fix("    this      is      text");
    return 0;
}
#include <iostream> 
#include <string> 
#include <sstream> 
#include <vector>
#include <fstream>

using namespace std; 

int read_int(const string& prompt) {
    cout << prompt; 
    int n; 
    while (!(cin >> n)) { // did not successfully read the int (also extracts n if successful)
        // while not able to extrct int from cin
        // need to clean buffer
        cin.clear(); // resets fail state to stream can try reading agian (need to clear fist since if in fail state all further operations immediately fail)
        string dummy; 
        getline(cin, dummy); // gets whats left in buffer and discards it
        cout << "please give me an int" << endl;
        cout << prompt;
        cin >> n;
    }
    return n;
}

void process_file(const string& name) {
    int sum = 0;
    ifstream input(name);
    while (!input.eof()) {
        int n;
        if (input >> n) {
            cout << "next int = " << n << endl;
            sum += n;
        } else {
            input.clear();
            string bad; 
            if (input >> bad) { // for case of empty spaces @ end of file
                cout << "invalid token = " << bad << endl;
            }
        }
    }
    cout << "Overall sum = " << sum << endl;
}

string int_to_string(int n) { // in java autoamte string concatenation
    // insertion operator on stream automatically converts 
    ostringstream output; 
    output << n;
    return output.str();
}

// count number of words per line from input file
void count_words(const string& file) {
    cout << "word counts for file" << file << endl;
    ifstream input(file);
    int line_count = 0;
    string line;
    while (getline(input, line)) { // returns reference to stream that reading from
        line_count++;
        int word_count = 0; 
        istringstream line_data(line);
        string token;
        while (line_data >> token) {
            word_count++;
        }
        cout << "    line # " << line_count << " has " << word_count << " word(s)" << endl;

    }
}

string vector_to_sring(const vector<int>& v) {
        ostringstream out; 
        out << "[";
        if (v.size() > 0) {
            out << v[0];
            for (int i = 1; i < v.size(); i++) {
                out << ", " <<  v[i];
            }
        }
        out << "]";
        return out.str();
}

int main() {
    int n = read_int("give me an int: ");
    cout << n << endl;
    process_file("data.txt");

    // output streams creating files
    ofstream output; 
    output.open("foo1.txt");
    output << "hello word" << endl; 
    output.close(); 
    output.open("foo2.txt");
    output << "hello again" << endl;
    cout << "created 2 new files successfully" << endl;
    int x = 3, y = 4;
    string s = "x =" + int_to_string(x) + ", y = " + int_to_string(y);
    string s2 = "x = " + to_string(x) + ", y = " + to_string(y);
    cout << s << endl;
    cout << s2 << endl;
    count_words("jabberwocky.txt");
    string res = vector_to_sring({2, 3, 5, 7, 11});
    cout << endl << res << endl;
    return 0;
}



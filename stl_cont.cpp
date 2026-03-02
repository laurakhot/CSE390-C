
#include <vector>
#include <iostream>
#include <set>
#include <numeric>
#include <fstream>
using namespace std;

ostream& operator<<(ostream& out, const vector<int>& v) {
    out << "[";
    if (!v.empty()) {
        out << v[0];
        for (size_t i = 1; i < v.size(); i++) {
            out << ", " << v[i];
        }
    }
    out << "]";
    return out;
}

int main() {
    vector<int> v1{1,2,3,4,5,3,28,4,5,6,3,17};
    vector<int> v2{843, -7, 14, 2, 5, 7, 3, 45, 90, 13, 24};
    cout << v1 << endl;
    set<int> s2 = {12, 5, 7, 2, -8, 56, 17, 2};
   
    // find a 3 in v1, change to 42
    // vector<int>::iterator find(v1.begin(), v1.end(), 3) // first occurence o=in [start, end) or end if not found (returns iterator)
    auto itr = find(v1.begin(), v1.end(), 3);
    if (itr == v1.end()) {
        cout << "not found" << endl; 
    } else {
        *itr = 42;
    }
    cout << "v1 = " << v1 << endl;

    // find 7 in set, change to 42
    auto itr2 = find(s2.begin(), s2.end(), 7);
    // ILLEGAL: *itr2 = 42;
    cout << (itr2 == s2.end()) << endl; // want to know if value found (0 = false, 1 = true)

    // count # of 3s in v1: 
    // count(start, end, value) -> set always returns 0 or 1 for count
    int n = count(v1.begin(), v1.end(), 3);
    cout << "count = " << n << endl;

    // find equal sequence in v1 and v2, v1 and s
    // equal(start1, end1, start2, end2)
    // cout << equal(v1.begin() + 5, v1.begin() + 10, 
    //               v2.begin() + 4, v2.begin() + 9) << endl;
    // cout << endl;

    // replace(start, end, old_val, new_val)
    // replace 3 with -8 in v1, reaplce 2 with 15 in s
    replace(v1.begin(), v1.end(), 3, -8); // replaces all instances of the value
    cout << "v1 = " << v1 << endl;

    // ILLEGAL: can't call replace on a set: replace(s2.begin(), s2.end(), 2, 15);

    // reverse v1, s
    // reverse(start, stop) -> can reverse part of vector 1
    reverse(v1.begin(), v1.end());
    cout << "v1 = " << v1 << endl;

    // ILLEGAL: Can't decide ordering of set -> reverse(s2.begin(), s2.end()); 

    // sort v1, call is_sorted(start, stop) -> returns whether values in range are sorted
    sort(v1.begin(), v1.end()); // sort(start, end) -> sorted elements [start, end)
    cout << "v1 = " << v1 << endl;
    cout << is_sorted(v1.begin(), v1.end()) << endl;

    cout << is_sorted(s2.begin(), s2.end()) << endl; // will return true since sets always in sorted order

    // shuffle v1, call is_sorted 
    // random_shuffle(start, stop)
    random_shuffle(v1.begin(), v1.end()); 
    cout << is_sorted(v1.begin(), v1.end()) << endl;

    // sort v1, v2, merge into v3 (v1 and v2 must be sorted)
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    vector<int> v3(v1.size() + v2.size() + 3); // must make vector big enough to hold all elements otherwise will be overwriting other locations in memory
    merge(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
    cout << "v3 = " << v3 << endl;

    // add up values in v1
    int sum = accumulate(v1.begin(), v1.end(), 0);
    cout << "v1 sum = " << sum << endl;

    string phrase; 
    cout << "phrase to use? "; 
    cin >> phrase; 
    sort(phrase.begin(), phrase.end());
    for (char & ch : phrase) { // must be reference to character to actually change
        ch = tolower(ch);
    }
    // find anagrams 
    ifstream input("dictionary.txt"); 
    string word; 
    while (input >> word) {
        string copy = word;
        sort(word.begin(), word.end());
        if (word == phrase) {
            cout << copy << endl;
        }
    }

    return 0;
}
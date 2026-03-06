#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <cctype>
#include <numeric>
using namespace std;

template<typename T>
// structure needs to have a begin & end 
// structure's element type must have overriden insertion operator to put onto output stream
string to_string(T data) {
    ostringstream out; 
    out << "["; 
    auto itr = data.begin();
    if (itr != data.end()) {
        out << *itr;
        ++itr;
        while (itr != data.end()) {
            out << ", " << *itr;
            ++itr;
        }
    }
    out << "]";
    return out.str();
}

bool less_size(const string & lhs, const string & rhs) {
    return lhs.size() < rhs.size();
}

void print_char(char ch) {
    cout << ch << endl; 
}

int main() {
    vector<string> v1 {"hello", "four", "a", "smile", "seven", "ago", "our", "fathers","brought", "forth", "on", "this", "continent", "new", "nation", "liberty", "and", "delicated", "the", "proposition"};
    sort(v1.begin(), v1.end());
    cout << "words after sorting" << to_string(v1) << endl;
    cout << endl;

    stable_sort(v1.begin(), v1.end(), less_size); // passing the address as a param
    cout << "words after custom sorting" << to_string(v1) << endl;
    cout << endl;

    // lambdas - anonymous functions 
    string s = "Hello there!";
    for_each(s.begin(), s.end(), print_char);
    // [...](parameters){lambda}
    for_each(s.begin(), s.end(), [](char ch) { cout << ch << endl; });
    for_each(s.begin(), s.end(), [](char & ch) { ch = tolower(ch); });
    cout << "s = " << s << endl;

    vector<int> nums1 {1, 2, 3, 6, 8, 12, 23, 5, 73, 32};
    cout << "nums1 = " << to_string(nums1) << endl;
    int sum = accumulate(nums1.begin(), nums1.end(), 0);
    cout << "sum = " << sum << endl;
    // reduce/ folding function
    // int product = accumulate(nums1.begin(), nums1.end(), 1, 
    //                          [](int x, int y) { return x * y; });
    int product = accumulate(nums1.begin(), nums1.end(), 1, multiplies<int>());
    cout << "product = " << product << endl;
    vector<int> nums2;
    // filter function (keep only multiples of 3)
    copy_if(nums1.begin(), nums1.end(), back_inserter(nums2), 
    [](int n) { return n % 3 == 0; });
    cout << "nums2 = " << to_string(nums2) << endl;

    int max; 
    cout << "max int? ";
    cin >> max; 
    vector<int> nums3; 
    auto f = [&max](int n) {return n <= max;};
    max = max - 10;
    copy_if(nums1.begin(), nums1.end(), back_inserter(nums3), f); // need to capture max since need it to do lambda
    cout << "nums3 = " << to_string(nums3) << endl;
}
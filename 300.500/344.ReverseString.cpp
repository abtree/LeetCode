#include <iostream>
#include <vector>
#include <utility>

using namespace std;

class ReverseString {
public:
    void reverseString(vector<char>& s) {
        int b = 0, e = s.size() - 1;
        while (b < e) {
            swap(s[b], s[e]);
            ++b;
            --e;
        }
    }
};

int main(int argc, char const* argv[]) {
    ReverseString cls;
    vector<char> vec{ 'h','e','l','l','o' };
    cls.reverseString(vec);
    cout << "[";
    for (auto c : vec) {
        cout << c << ",";
    }
    cout << "]" << endl;

    vector<char> vec1{ 'H','a','n','n','a','h' };
    cls.reverseString(vec1);
    cout << "[";
    for (auto c : vec1) {
        cout << c << ",";
    }
    cout << "]" << endl;

    return 0;
}

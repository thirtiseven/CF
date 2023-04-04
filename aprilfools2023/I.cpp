#include <iostream>
using namespace std;

string mountain_climber(string s) {
    string result = "YES";
    for (int i = 1; i < s.length(); i++) {
        if (s[i] > s[i-1]) {
            if (i > 1 && s[i-1] > s[i-2]) {
                result = "NO";
                break;
            }
        } else if (s[i] < s[i-1]) {
            if (i > 1 && s[i-1] < s[i-2]) {
                result = "NO";
                break;
            }
        }
    }
    return result;
}

int main() {
    int T;
    string s;
    cin >> T;
    while (T--) {
        cin >> s;
        cout << mountain_climber(s) << endl;
    }
    return 0;
}

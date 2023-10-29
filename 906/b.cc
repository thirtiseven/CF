#include <iostream>
#include <algorithm>
#include <string>

std::string s, t;
int T;
int n, m;

bool one_string(std::string& a) {
    // check if a is string like 1, 101, 1010101...
    int len = a.length();
    if (len % 2 == 0) {
        return false;
    }
    for (int i = 0; i < len; ++i) {
        if (i % 2 == 0 && a[i] != '1') return false;
        if (i % 2 == 1 && a[i] != '0') return false;
    }
    return true;
}

bool zero_string(std::string& a) {
    // check if a is string like 0, 010, 0101010...
    int len = a.length();
    if (len % 2 == 0) {
        return false;
    }
    for (int i = 0; i < len; ++i) {
        if (i % 2 == 0 && a[i] != '0') return false;
        if (i % 2 == 1 && a[i] != '1') return false;
    }
    return true;
}

int main(int argc, char *argv[]) {
    std::cin >> T;
    while (T--) {
        std::cin >> n >> m >> s >> t;
        if (one_string(t)) {
            // check if s contains adjacent 0s
            int len = s.length();
            bool yes = true;
            for (int i = 0; i < len-1; ++i) {
                if (s[i] == '1' && s[i+1] == '1') {
                    yes = false;
                }
            }
            if (yes) {
                std::cout << "Yes\n";
            } else {
                std::cout << "No\n";
            }
        } else if (zero_string(t)) {
            // check if s contains adjacent 1s
            int len = s.length();
            bool yes = true;
            for (int i = 0; i < len-1; ++i) {
                if (s[i] == '0' && s[i+1] == '0') {
                    yes = false;
                }
            }
            if (yes) {
                std::cout << "Yes\n";
            } else {
                std::cout << "No\n";
            }
        } else {
            // check if s is already 101010...
            for (int i = 0; i < s.length() - 1; i++) {
                if (s[i] == s[i+1]) {
                    std::cout << "No\n";
                    goto label;
                }
            }
            std::cout << "Yes\n";
            label:;
        }
    }
}
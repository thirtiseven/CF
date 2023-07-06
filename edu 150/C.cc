#include <iostream>
#include <algorithm>
#include <string>

std::string s;
using ll = long long;

ll gao(char x) {
    switch (x) {
        case 'A': return 1;
        case 'B': return 10;
        case 'C': return 100;
        case 'D': return 1000;
        case 'E': return 10000;
        default: return 0;
    }
}

int main(int argc, char *argv[]) {
	int t;
    std::cin >> t;
    while (t--) {
        std::cin >> s;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != 'E') {
                s[i] = 'E';
                break;
            }
        }
        ll sum = 0;
        char cur = 'A';
        std::cout << s << '\n';
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] >= cur) {
                sum += gao(s[i]);
                cur = s[i];
            } else {
                sum -= gao(s[i]);
            }
        }
        std::cout << sum << '\n';
    }
}
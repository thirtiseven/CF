#include <iostream>
#include <string>

const int maxn = 103;

int t, n;
std::string s;
int e[30], o[30];

int main() {
    std::cin >> t;
    while (t--) {
        for (int i = 0; i < 26; i++) {
            e[i] = o[i] = 0;
        }
        std::cin >> n >> s;
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                e[int(s[i]-'a')] = 1;
            } else {
                o[int(s[i]-'a')] = 1;
            }
        }
        bool yes = 1;
        for (int i = 0; i < 26; i++) {
            if (e[i] == 1 && o[i] == 1) {
                yes = 0;
            }
        }
        std::cout << (yes?"YES":"NO") << "\n";
    }
}
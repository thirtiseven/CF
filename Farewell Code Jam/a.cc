#include <iostream>
#include <string>
#include <set>

using ll = long long;

int d[30];
std::set<std::string> st;

int main() {
    int T;
    std::cin >> T;
    for (int CASE = 1; CASE <= T; ++CASE) {
        st.clear();
        bool yes = false;
        for (int i = 0; i < 26; i++) {
            std::cin >> d[i];
        }
        int n;
        std::cin >> n;
        for (int i = 0; i < n; i++) {
            std::string s;
            std::cin >> s;
            std::string encode = "";
            for (char c : s) {
                encode = encode + char(d[int(c - 'A')] + '0');
            }
            // std::cout << encode << std::endl;
            st.insert(encode);
        }
        std::cout << "Case #" << CASE << ": " << (st.size() == n ? "NO" : "YES") << std::endl;
    }
}
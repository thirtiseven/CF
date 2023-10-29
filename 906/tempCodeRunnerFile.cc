#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

int T, n;
std::string s;

int main(int argc, char *argv[]) {
    std::cin >> T;
    while (T--) {
        std::cin >> n >> s;
        int zero_num = 0, one_num = 0;
        for (auto c : s) {
            if (c == '0') {
                zero_num++;
            } else {
                one_num++;
            }
        }
        if (zero_num == one_num) {
            std::vector<int> res;
            int lpos = 0, rpos = n-1;
            int offset = 1;
            while (lpos < rpos) {
                if (s[lpos] != s[rpos]) {
                    lpos++;
                    rpos--;
                } else {
                    if (s[lpos] == '0') {
                        res.push_back(rpos+offset);
                        rpos++;
                        lpos++;
                        s += "0";
                    } else {
                        res.push_back(lpos);
                        offset += 2;
                        s = "1" + s;
                    }
                }
            }
            std::cout << res.size() << '\n';
            for (auto x : res) {
                std::cout << x << " ";
            }
            std::cout << '\n';
        } else {
            std::cout << "-1\n";
        }
    }
}
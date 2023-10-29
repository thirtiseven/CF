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
            int offset = 0;
            int cnt = 0;
            while (lpos < rpos) {
                // std::cout << lpos << ' ' << rpos << ' ' << s << '\n';
                if (res.size() > 300) {
                    break;
                }
                if (s[lpos] != s[rpos]) {
                    lpos++;
                    rpos--;
                } else {
                    if (s[lpos] == '0') {
                        res.push_back(rpos + 1);
                        s.insert(rpos+1, "01");
                        rpos += 2;
                    } else {
                        res.push_back(lpos);
                        s.insert(lpos, "01");
                        rpos += 2;
                    }
                }
            }
            if (res.size() > 300) {
                std::cout << "-1\n";
                continue;
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
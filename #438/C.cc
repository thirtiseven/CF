#include <iostream>
#include <cmath>
#include <algorithm>
#include <set>
#include <cstring>
#include <vector>

int main(int argc, char *argv[]) {
    std::ios::sync_with_stdio(false);
    int n, k;
    bool flag = 0;
    int aaa[20];
    std::vector<int> aaaa;
    memset(aaa, 0, sizeof(aaa));
    int tt;
    std::cin >> n >> k;
    for(int i = 0; i < n; i++) {
        int temp = 0;
        for(int j = 0; j < k; j++) {
            std::cin >> tt;
            temp = (temp << 1) + tt;
        }
        aaa[temp] = 1;
    }
    for(int i = 0; i < 17; i++) {
        if(aaa[i] == 1) {
            aaaa.push_back(i);
        }
    }
    for(int mmm = 0; mmm < aaaa.size(); mmm++) {
        for(int j = 0; j < aaaa.size(); j++) {
            int alice = aaaa[mmm];
            int bob = aaaa[j];
            if(alice == bob) {
                continue;
            }
            if((alice & bob) == 0) {
                flag = 1;
                goto out;
            }
        }
    }
    out:
    if(aaaa.size() == 1 && aaaa[0] == 0) {
        flag = 1;
    }
    std::cout << (flag?"YES":"NO");
    return 0;
}
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#define maxn 200010

int main(int argc, char *argv[]) {  
	int n, a[maxn];
	std::multiset<int> num;
	std::vector<int> non;
	std::cin >> n;
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
		num.insert(a[i]);
	}
	for(int i = 1; i <= n; i++) {
		if(num.count(i)==0) {
			non.push_back(i);
		}
	}
	std::sort(non.begin(), non.end());
	for(int i = 0; i < non.size(); i++) {
		std::cout << non[i] << " ";
	}
	std::cout << std::endl;
	int cnt = 0;
	for(int i = 0; i < n; i++) {
		if(num.count(a[i]) > 1) {
			a[i] = non[cnt];
			cnt++;
			for(std::set<int>::iterator it = num.begin(); it != num.end(); it++) {
				if(*it == a[i]) {
					num.erase(it);
					break;
				}
			}
		}
	}
	std::cout << cnt << std::endl;
	for(int i = 0; i < n; i++) {
		std::cout << a[i] << " ";
	}
	return 0;
}
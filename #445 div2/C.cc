#include <iostream>
#include <set>

int main(int argc, char *argv[]) {  
	int n;
	int temp;
	std::set<int> a;
	std::cin >> n;
	for(int i = 0; i < n; i++) {
		std::cin >> temp;
		a.insert(temp);
	}
	int cnt = 0;
	for(int i = 1; i <= n; i++) {
		if(a.count(i) == 0) {
			cnt++;
		}
	}
	std::cout << cnt << std::endl;
	return 0;
}
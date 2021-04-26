#include <iostream>
#include <algorithm>

int n;

int query(int x) {
	std::cout << "? " << x << std::endl;
	int res;
	std::cin >> res;
	return res;
}

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> n;
	int l = 0, r = n+1, lmid, rmid, x = 0, y = 100000;
	while (r-l > 2) {
//		std::cout << l << ' ' << r << '\n';
		lmid = l + (r - l)/3;
		rmid = r - (r - l)/3;
		int x = query(lmid);
		int y = query(rmid);
		if (x < y) {
			r = rmid;
		} else {
			l = lmid;
		}
	}
	std::cout << "! " << l+1 << std::endl;
}
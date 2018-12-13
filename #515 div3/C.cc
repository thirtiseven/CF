#include <iostream>
#include <map>

std::map<int, int> pos;

int main(int argc, char *argv[]) {  
	int q, num;
	char ch;
	std::cin >> q;
	int l = 1, r = 0;
	for (int i = 0; i < q; i++) {
		std::cin >> ch >> num;
		if (ch == 'L') {
			l--;
			pos[num] = l;
		} else if (ch == 'R') {
			r++;
			pos[num] = r;
		} else {
			std::cout << std::min(pos[num]-l, r-pos[num]) << '\n';
		}
	}
}
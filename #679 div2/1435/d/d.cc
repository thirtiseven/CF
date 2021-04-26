#include <iostream>
#include <algorithm>

const int maxn = 1e5+7;

int x[maxn*2], pos[maxn];

char op;
int a;

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> n;
	for (int i = 0; i < 2*n; i++) {
		std::cin >> op;
		if (op == '+') {
			x[i] = -1;
		} else {
			std::cin >> a;
			x[i] = a;
			pos[a] = i;
		}
	}
}
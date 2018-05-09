#include <iostream>
#include <cstring>

int garden[1000][1000];

bool hastaken(int l, int c) {
	if (garden[l-1][c-1] && garden[l][c-1] && garden[l+1][c-1] && garden[l-1][c] && garden[l][c] && garden[l+1][c] && garden[l-1][c+1] && garden[l][c+1] && garden[l+1][c+1]) {
		return true;
	}
	return false;
}

bool hasc(int l, int c) {
	if (garden[l-1][c-1] && garden[l-1][c] && garden[l-1][c+1]) {
		return true;
	}
	return false;
}

int main(int argc, char *argv[]) {  
	memset(garden, 0, sizeof(garden));
	int T;
	std::cin >> T;
	while (T--) {
		int A;
		std::cin >> A;
		int l = 5, c = 500;
		int il, ic;
		int taken = 0;
		while (taken <= A) {
			while (!hastaken(l, c)) {
				std::cout << l << ' ' << c << std::endl;
				std::cin >> il >> ic;
				if (!il&&!ic) {
					goto outside;
				}
				garden[il][ic] = 1;
			}
			taken += 9;
			l += 3;			
		}
		outside:;
	}
}
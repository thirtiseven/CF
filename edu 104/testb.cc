#include <iostream>
#include <algorithm>

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	int cnt = 100;
	int n;
	std::cin >> n;
	int A = n, B = 1;
	while (cnt--) {
		std::cout << A << ' ' << B << ' ';
		A--;
		if (A == 0) {
			A = n;
		}
		B++;
		if (B == n+1) {
			B = 1;
		}
		if (A == B) {
			std::cout << "!";
			B++;
			if (B == n+1) {
				B = 1;
			}
 		}
		std::cout << '\n';
	}
}
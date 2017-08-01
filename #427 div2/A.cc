#include <iostream>

int main(int argc, char *argv[]) {  
	int s, v1, v2, t1, t2;
	std::cin >> s >> v1 >> v2 >> t1 >> t2;
	if(s * v1 + 2 * t1 == s * v2 + 2 * t2) {
		std::cout << "Friendship";
	} else if (s * v1 + 2 * t1 < s * v2 + 2 * t2) {
		std::cout << "First";
	} else {
		std::cout << "Second";
	}
	return 0;
}
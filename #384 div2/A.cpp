#include <iostream>

int main(int argc, char *argv[]) {  
	int n, a, b;
	char s[100010];
	std::cin >> n >> a >> b;
	std::cin >> s;
	if(s[a-1] == s[b-1]) {
		std::cout << "0\n";
	} else {
		std::cout << "1\n";
	}
	return 0;
}
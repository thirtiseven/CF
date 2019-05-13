#include <iostream>
#include <string>

int x = 29;

bool check(int a) {
	std::string s = std::to_string(a);
	int sum = 0;
	int len = s.length();
	if (s[len-1] != '9' || s[len-2] != '2') {
		return 0;
	}
	for (auto it: s) {
		sum += int(it-'0');
	}
	if (sum == 29) {
		return 1;
	}
	return 0;
}

int main(int argc, char *argv[]) {  
	while (!check(x)) {
		x += 29;
	}
	std::cout << x;
}
#include <iostream>
#include <string>

std::string a, b;
int n;

int main(int argc, char *argv[]) {  
	std::cin >> n >> a >> b;
	if (a[0] == b[1] && a[1] != b[0] && a[0] != a[1]) {
		std::cout << b << a[1];
	}
}
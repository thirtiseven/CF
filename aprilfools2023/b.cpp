#include <iostream>

using namespace std;
int main(int argc, char *argv[]) {
	int n;
	cin >> n;
	if (n == 4 || n == 6 || n == 9 || n == 12 || n == 14 || n == 16 || n == 18 || n == 20 || n == 21 || n == 22 || n == 25) {
		std::cout << "NO\n";
	} else {
		std::cout << "YES\n";
	}
}
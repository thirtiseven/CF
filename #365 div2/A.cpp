#include <iostream>

int main(int argc, char *argv[]) {  
	int n, m[110], c[110];
	int win = 0, los = 0;
	std::cin >> n;
	for(int i = 0; i < n; i++) {
		std::cin >> m[i] >> c[i];
		if(m[i] > c[i]) {
			win++;
		} else if(m[i] < c[i]) {
			los++;
		}
	}
	if(win == los) {
		std::cout << "Friendship is magic!^^" << std::endl;
	} else if(win > los) {
		std::cout << "Mishka" << std::endl;
	} else {
		std::cout << "Chris" << std::endl;
	}
	return 0;
}
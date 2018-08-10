#include <iostream>
#include <set>

std::set<int> s;

int main(int argc, char *argv[]) {
	int tmp, n;
	std::cin >> n;
	for (int i=0; i<n; i++) {
		std::cin >> tmp;
		s.insert(tmp);
	}
	for (int i: s) {
		for (int j=0; j<31; j++){
			int bit=(1<<j);
			if (s.count(i-bit)&&s.count(i+bit)) {
				std::cout << "3" << std::endl << i-bit << " " << i << " " << i+bit << std::endl;
				exit(0);
			}
		}
	}
	for (int i:s) {
		for (int j=0; j<31; j++) {
			int bit=(1<<j);
			if(s.count(i-bit)) {
				std::cout << "2" << std::endl << i-bit << " " << i << std::endl;
				exit(0);
			}
		}
	}
	std::cout << 1 << std::endl << *s.begin() << std::endl;
}
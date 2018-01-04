#include <iostream>
#include <string>
#include <cmath>

std::string s1 = "STRIKE\n";
std::string s2 = "HEAL\n";

int main(int argc, char *argv[]) {  
	double h1, a1, c1;
	double h2, a2;
	std::cin >> h1 >> a1 >> c1;
	std::cin >> h2 >> a2;
	int roun = ceil(h2/a1);
	int heal = ceil(((roun-1) * a2 - h1) / (c1-a2) + 0.01);
//	if(int((roun-1) * a2 - h1) % int(c1-a2) == 0) {
//		heal++;
//	}
	std::cout << std::max(heal, 0) + roun << '\n';
	for(int i = 0; i < std::max(heal, 0); i++) {
		std::cout << s2;
	}
	for(int i = 0; i < roun; i++) {
		std::cout << s1;
	}
	return 0;
}
#include <iostream>

int main(int argc, char *argv[]) {  
	int r, d, s;
	std::cin >> r >> d >> s;
	int lane = (s-1) / (2 * d) + 1;
	int group = s % (2 * d);
	if(group == 0) group = 2 * d;
	if(group%2==1) std::cout << lane << " " << (group-1)/2+1 << " " << "L";
	else std::cout << lane << " " << (group-1)/2+1 << " " << "R";
	return 0;
}
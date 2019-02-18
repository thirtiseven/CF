#include <iostream>
#include <fstream>
std::ifstream fin ("text.in");

int main(int argc, char *argv[]) {  
	int n, xs = 0, ys = 0, x, y;
	fin >> n;
	for (int i = 0; i < 2*n; i++) {
		fin >> x >> y;
		xs += x;
		ys += y;
	}
	std::cout << xs/n << " " << ys/n;
}
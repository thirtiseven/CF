#include <iostream>
#include <fstream>
std::ofstream fout ("text.in");

const int xx = 1e6;
const int xxx = 2e6-1000;
const int xxxx = 2e6;

int main(int argc, char *argv[]) {  
	fout << "1000\n";
	for (int i = 0; i < 1000; i++) {
		fout << xx-i << " " << xx << '\n';
	}
	for (int i = 0; i < 1000; i++) {
		fout << xxx+i << " " << xxxx << '\n';
	}
}
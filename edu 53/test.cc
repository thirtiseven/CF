#include <iostream>
#include <fstream>
std::ofstream fout ("aaa.in"); 

int main(int argc, char *argv[]) {  
	fout << "200000 1000000000000000000\n";
	for (int i = 0; i < 200000; i++) {
		fout << "1000000000 ";
	}
}
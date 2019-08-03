#include <iostream>
#include <string>
#include <fstream>

std::ifstream fin ("leapfrog_ch_.txt"); 
std::ofstream fout ("xx.txt"); 

int main(int argc, char *argv[]) {  
	int T;
	std::string s;
	fin >> T;
	for (int CAS = 1; CAS <= T; CAS++) {
		fin >> s;
		int len = s.length();
		int forg_b = 0;
		for (auto it: s) {
			if (it == 'B') {
				forg_b++;
			}
		}
		if (forg_b >= len/2 && forg_b <= len-2) {
			fout << "Case #" << CAS << ": Y\n";
		} else {
			fout << "Case #" << CAS << ": N\n";
		}
	}
}
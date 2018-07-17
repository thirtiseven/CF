#include <iostream>
#include <string>
#include <set>

std::set<char> s;

int main(int argc, char *argv[]) {  
	s.insert('a');
	s.insert('o');
	s.insert('u');
	s.insert('i');
	s.insert('e');
	std::string ss;
	std::cin >> ss;
	bool yes = 1;
	if (s.count(ss[ss.length()-1]) != 1 && ss[ss.length()-1] != 'n') {
		yes = 0;
	}
	for (int i = 0; i < ss.length()-1; i++) {
		if (s.count(ss[i])!=1 && ss[i] != 'n') {
			if (s.count(ss[i+1])!=1) {
				yes = 0;
			}
		}
	}
	std::cout << (yes?"YES":"NO");
}
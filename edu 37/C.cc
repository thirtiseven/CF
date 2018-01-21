#include <string>
#include <iostream>
#include <algorithm>

using ll = long long;

int main(int argc, char *argv[]) {
	std::string a;
	ll b;
	std::cin >> a >> b;
	std::sort(a.begin(), a.end());
	for(int i = 0; i < a.length(); i++) {
		for(int j = i+1; j < a.length(); j++) {
			std::string tmp = a;
			std::swap(tmp[i], tmp[j]);
			std::sort(tmp.begin()+i+1, tmp.end());
			if(std::stoll(tmp) > std::stoll(a) && std::stoll(tmp) <= b) {
				std::swap(a[i], a[j]);
			}
		}
	}
	std::cout << a;
}
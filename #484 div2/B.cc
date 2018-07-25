#include <iostream>
#include <queue>
#include <vector>
#include <string>

std::priority_queue<std::pair<int, int>> a;
std::priority_queue<std::pair<int, int>> b;

int main(int argc, char *argv[]) {  
	int n, t;
	std::cin >> n;
	for (int i = 1; i <= n; i++) {
		std::cin >> t;
		a.push(std::make_pair(-t, i));
	}
	std::string s;
	std::cin >> s;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '0') {
			std::cout << a.top().second << " ";
			b.push(std::make_pair(-(a.top().first), a.top().second));
			a.pop();
		} else {
			std::cout << b.top().second << " ";
			b.pop();
		}
	}
}
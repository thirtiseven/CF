#include <iostream>
#include <set>

using ll = long long;

std::set<ll> a, b;

int main(int argc, char *argv[]) {  
	ll aa, bb;
	std::cin >> aa >> bb;
	ll k = 1;
	while (k*(k+1) <= 2*(aa+bb)) {
		k++;
	}
	ll cur = k-1;
	while (cur >= 1 && (aa >= cur || bb >= cur)) {
		if (aa >= cur) {
			aa-=cur;
			a.insert(cur);
			cur--;
		} else if (bb >= cur) {
			bb-=cur;
			b.insert(cur);
			cur--;
		}
	}
	if (a.size() == 0 && b.size() == 0) {
		std::cout << "0 0\n";
		exit(0);
	}
	std::cout << a.size() << '\n';
	for (auto it: a) {
		std::cout << it << " ";
	}
	std::cout << '\n';
	std::cout << b.size() << '\n';
	for (auto it: b) {
		std::cout << it << " ";
	}
	std::cout << '\n';
}
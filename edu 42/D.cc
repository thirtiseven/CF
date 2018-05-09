#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <utility>

using ll = long long;

int main(int argc, char *argv[]) {  
	int n;
	std::set<std::pair<ll, int> > aa;
	ll arr[151234];
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> arr[i];
		aa.insert(std::make_pair(arr[i], i));
	}
	while (aa.size() >= 2) {
		std::set<std::pair<ll, int> >::iterator x = aa.begin();
		std::set<std::pair<ll, int> >::iterator y = (x++);
		if ((x->first) == (y->first)) {
			(y->first) = (y->first*2);
		}
	}
}
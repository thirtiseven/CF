#include <iostream>
#include <vector>
#include <cstring>

#define ll long long
#define maxn 100010

int main(int argc, char *argv[]) { 
	ll n, k;
	ll c[maxn], id[maxn], id_sort[maxn];
	ll sum_node = 0, ans = 0, sum_ca_value = 0;
	ll city[maxn];
	memset(id, 0, sizeof(id));
	std::cin >> n >> k;
	for(int i = 0; i < n; i++) {
		std::cin >> c[i];
		sum_node += c[i];
	}
	for(int i = 0; i < k; i++) {
		std::cin >> id_sort[i];
		id_sort[i]--;
		id[id_sort[i]]++;
		sum_ca_value += c[id_sort[i]];
		ll neibour = c[(id_sort[i]+n-1)%n] + c[(id_sort[i]+1)%n];
		ans += (sum_node - sum_ca_value - neibour) * c[id_sort[i]];
	}
	int cnt = 0;
	for(int i = 0; i < n; i++) {
		if(!id[i]) {
			city[cnt] = c[i];
		}
		cnt++;
	}
	for(int i = 0; i < n; i++) {
		ans += c[i] * c[(i+1)%n];
	}
	
	/*
	for(int i = 0; i < k; i++) {
		ans -= c[(id_sort[i]+n-1)%n] * c[id_sort[i]];	
		if(!id[(i+1)%n]) {
			ans -= c[(id_sort[i]+1)%n] * c[id_sort[i]];		
		}
	}
	*/
	
	std::cout << ans << std::endl;
	return 0;
}
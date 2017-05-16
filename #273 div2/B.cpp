#include <iostream>

#define ll long long int

ll pair_of_team(ll num){
	ll pair = num * (num - 1) / 2;
	return pair;
}

int main(int argc, char *argv[]) {
	ll n, m;
	std::cin >> n >> m;
	ll num_less = n / m;
	ll num_more = n / m + 1;
	ll gro_less = m - n%m;
	ll gro_more = n % m;
	//std::cout << less_group_min << " " << more_group_min << std::endl;
	ll min = gro_less * pair_of_team(num_less) + gro_more * pair_of_team(num_more);
	ll max = pair_of_team(n-m+1);
	std::cout << min << " " << max << std::endl;
	return 0;
}
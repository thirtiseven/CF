#include <iostream>
#include <algorithm>

#define ll long long

int main(int argc, char *argv[]) {
	ll begin, end, t, vis, vist[100100];
	ll before[100100],just[100100];
	ll ls = 1e12;
	std::cin >> begin >> end >> t;
	std::cin >> vis;
	ll temp,thistime = 0;
	ll min = 10e13;
	for(int i = 0; i < vis; i++){
		std::cin >> vist[i];
		temp = i;
		if(vist[i]+t>end || vist[i]==0){
			thistime = t;
			continue;
		}
		if((std::max(vist[i] - 1 + t,begin) <= end || begin + t <=end) && std::min(vist[i] - 1, begin)<min){
			min = std::min(vist[i] - 1, begin);
		}
		begin = std::max(begin, vist[i]) + t;
	}
	if(begin + t <= end){
		min = begin;
	}
	std::cout << min << std::endl;
}
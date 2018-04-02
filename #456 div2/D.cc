#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <queue>
#include <set>
#include <utility>

const int maxn = 1e5+2;

double n, m, r, k;
double times;

double v(double i, double j) {
	return (std::min(n+1, i+r)-std::max(i,r))*(std::min(m+1, j+r)-std::max(j, r));
}

std::priority_queue<double> aaa;
std::set<std::pair<double, double> ss;

int main(int argc, char *argv[]) {  
	std::cin >> n >> m >> r >> k;
	times = (n-r+1)*(m-r+1);
	double ans = 0;	
	aaa.push(v(r, r));
	ss.insert(std::make_pair(r, r));
	while(k) {
		
	}
	std::cout << std::fixed << std::setprecision(12) << ans/times << std::endl;
}
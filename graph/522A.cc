#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <utility>
#define inf 400000
#define maxn 210

std::string trans_to_lowerword(std::string x) {
	int len = x.length();
	for ( int i = 0 ; i < len ; i++)
	{
		if (x[i]>='A'&&x[i]<='Z')
		{
			x[i] = char(x[i]+32);
		}
	}
	return x;
}

int main(int argc, char *argv[]) {  
	int n;
	std::cin >> n;
	int d[maxn][maxn];
	for(int i = 0; i < maxn; i++) {
		for(int j = 0; j < maxn; j++) {
			d[i][j] = inf;
		}
	}
	std::map<std::string, int> aa;
	int cnt = 0;
	for(int i = 0; i < n; i++) {
		std::string s, re, t;
		std::cin >> s >> re >> t;
		s = trans_to_lowerword(s);
		t = trans_to_lowerword(t);
		if(aa.find(s) == aa.end()) {
			aa.insert(std::pair<std::string, int>(s, cnt));
			cnt++;
		}
		if(aa.find(t) == aa.end()) {
			aa.insert(std::pair<std::string, int>(t, cnt));
			cnt++;
		}
		d[aa[s]][aa[t]] = 1;
		//std::cout << aa[s] << " " << aa[t] << '\n';
	}
	d[0][0] = 0;
	for(int k = 0; k < cnt; k++) {
		for(int i = 0; i < cnt; i++) {
			for(int j = 0; j < cnt; j++) {
				d[i][j] = std::min(d[i][j], d[i][k] + d[k][j]);		
				//std::cout << d[i][j] << "\n";
			}
		}
	}
	int ans  = 0;
	for(int i = 0; i < cnt; i++) {
		for(int j = 0; j < cnt; j++) {
			if(d[i][j] == inf) continue;
			ans = std::max(ans, d[i][j]);	
		}
	}
	std::cout << ans+1 << std::endl;
	return 0;
}
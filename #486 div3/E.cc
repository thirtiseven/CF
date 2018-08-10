#include <iostream>
#include <string>
#include <algorithm>

const int inf = 0x7f7f7f7f;
int ans;
std::string str;

void simu(std::string s, char a, char b) {	
	int cnt1 = s.rfind(a), cnt2 = s.rfind(b);
	if (a == '0' && b == '0') cnt1 = s.rfind(a, cnt1-1);
	if (cnt1 == std::string::npos || cnt2 == std::string::npos)
		return ;
	int cnt = 0;
	if (cnt1 > cnt2) cnt++, std::swap(cnt1, cnt2);
	for (int i = cnt2; i+1 < s.size(); i++) cnt++, std::swap(s[i], s[i+1]);
	for (int i = cnt1; i+1 < s.size()-1; i++) cnt++, std::swap(s[i], s[i+1]);
	cnt += find_if(s.begin(), s.end(), [](char c){ return c != '0'; }) - s.begin();
	ans = std::min(ans, cnt);
}

int main(int argc, char *argv[]) {  
	std::cin >> str;
	ans = inf;
	simu(str, '0', '0');
	simu(str, '2', '5');
	simu(str, '5', '0');
	simu(str, '7', '5');
	if (ans == inf) ans = -1;
	std::cout << ans;
	return 0;
}
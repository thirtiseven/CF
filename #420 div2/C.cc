#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

int main(int argc, char *argv[]) {
	char str[10];
	std::vector<int>p;
	int n,x,cnt,ans,d;
	std::cin >> n;
	 cnt=1;
	 ans=0;
	for(int i=1;i<=2*n;i++)
	{
	   std::cin >> str;
		if(str[0]=='a') {
			std::cin >> x;
			p.push_back(x);
		} else {
			if(p.empty());
			else if(p.back()==cnt) p.pop_back();
			else ans++,p.clear();
			cnt++;
		}
	}
	std::cout << ans << std::endl;
}
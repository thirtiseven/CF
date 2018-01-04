#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>

int n,num[30],ans,len;
bool f[30];
std::string s;


bool check(int p) {
	memset(f,false,sizeof(f));
	memset(num,0,sizeof(num));
	for(int i=0;i<p;++i)
		++num[s[i]-'a'];
	for(int i=0;i<26;++i)
		if(num[i])
			f[i]=true;
	for(int i=p;i<len;++i)
	{
		num[s[i-p]-'a']--;
		num[s[i]-'a']++;
		if(num[s[i-p]-'a']==0)
			f[s[i-p]-'a']=false;
	}
	for(int i=0;i<26;++i)
		if(f[i])
			return true;
	return false;
}

int main() {
	std::cin >> s;
	len=s.length();
	int l=1,r=len;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(check(mid))
		{
			ans=mid;
			r=mid-1;
		}
		else
			l=mid+1;
	}
	std::cout << ans;
	
	return 0;
}
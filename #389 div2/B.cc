#include <iostream> 
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <fstream>
#include <algorithm>
#include <queue>
#include <climits>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <vector>
#include <list>
const int INF = 1e9;
using namespace std;
typedef  long long ll;
typedef  unsigned long long  ull; 
	
string s1,s2;
map<char,char> mp;
set<char> st;
map<char,char>::iterator it;
int main()
{
	ios::sync_with_stdio(false);  
	cin >> s1>>s2;
	if(s1==s2)	
	{
		cout << "0"<<endl;
		return 0;
	}
	for(int i=0;i<s1.size();i++)
	{
		if(s1[i]!=s2[i])
		{
			if(st.count(s1[i])||st.count(s2[i]))
				continue;
			mp[s1[i]] = s2[i];
			st.insert(s1[i]);
			st.insert(s2[i]);
			char t1  = s1[i];
			char t2  = s2[i];
			for(int j=0;j<s1.size();j++)
			{
				if(s1[j]==t1)
				{
					s1[j] = t2;
					continue;
				}
				if(s1[j]==t2)	
				{
					s1[j] = t1;
				}
			}
		}
	}
	if(s1!=s2)
	{
		cout <<"-1"<<endl;
		return 0;
	} 
	int re = 0;
	vector<char> a;
	vector<char> b; 
	for(it = mp.begin();it!=mp.end();it++)
	{
			re++;
			a.push_back(it->first);
			b.push_back(it->second);
	}
	cout <<re<<endl;
	for(int i=0;i<re;i++)
	{
		cout << a[i]<<" "<<b[i]<<endl;
	}
	return 0;	
} 

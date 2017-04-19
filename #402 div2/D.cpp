#include <iostream>
#include <string>
#include <cstring>
#include <string.h>
#include <algorithm>
#include <regex>
#include <cmath>

using namespace std;

char t[200200],p[200200],mark[200200];
int del[200200];
int lent,lenp;

int check(int num)
{
	for(int i=0;i<lent;i++) mark[i] = 0;
	for(int i=0;i<num;i++) mark[del[i]] = 1;
	int leng=0, start = 0;
	for(int i=0;i<lent;i++)
	{
		if(!mark[i])
		{
			if(t[i] == p[start])
			{
				leng++;
				start++;
				if(leng >= lenp)
				{ 
					return 1;
				}
			}
		}
	}
	return 0;
}

int main(int argc, char *argv[]) {
	cin >> t;
	cin >> p;
	lent = strlen(t);
	lenp = strlen(p);
	del[lent] = 0;
	for(int i = 0;i < lent;i++){
		cin >> del[i];
		del[i]-=1;
	}
	int begin = 1,end = lent,ans = 0;
	int m;
	while(begin <= end){
		m = (begin + end)/2;
		if(check(m)){
			ans = max(ans, m);
			begin = m+1;
		}else{
			end = m-1;
		}
	}
	cout << ans << endl;
}
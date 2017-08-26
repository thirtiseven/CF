#include <iostream>  
#include <cstdio>  
#include <algorithm>  
#include <cstring>  
#include <cmath>  
  
#define MAXN 5005  
#define inf 0x3f3f3f3f  
#define ONES(x) __builtin_popcount(x)  
using namespace std;  
  
typedef long long ll ;  
const double eps =1e-8;  
const int mod = 1000000007;  
typedef pair<int, int> P;  
const double PI = acos(-1.0);  
int dx[4] = {0,0,1,-1};  
int dy[4] = {1,-1,0,0};  
  
int n,t;  
int ans;  
char str[200005];  
int main()  
{  
	//freopen("test.txt","r",stdin);  
	cin>>n>>t;  
	cin>>str;  
	int len = strlen(str);  
	int dot_pos = 0,pos = 0;//pos->the operation place  
	int flag = 0;  
	int last = len;//last标记截止的位置，时刻更新  
	for(int i = 0; i<len ; i++)//预处理部分，找到小数点的位置和小数点后面第一个大于5的数字的位置  
	{  
		if(str[i]=='.')  
			{dot_pos = i;flag = 1;}  
		if(flag==1 && str[i]-'5'>=0)  
			{pos = i;break;}  
	}  
	if(pos <= dot_pos)//特判小数点后没有大于5的数字的情况  
	{  
		for(int i = 0; i<len ; i++)  
			cout << str[i];  
		cout << endl;  
		return 0;  
	}  
	int m = len - dot_pos;  
	int k = 0;  
	while(k<min(m-1,t) && pos>dot_pos && str[pos]>='5')//进行最多k次四舍五入，位置不能超过小数点  
	{  
		if(pos-1 == dot_pos)  
			pos--;  
		while(str[pos-1]=='9')//处理9的进位的情况  
		{  
			pos--;  
			if(pos-1 == dot_pos)//可以越过小数点  
				pos--;  
			last = pos;  
		}  
		str[pos-1] += 1;  
		pos--;  
		last = pos;  
		k++;  
	}  
	//cout << last << endl;  
	for(int i = 0; i<=last ; i++)  
		cout << str[i];  
	if(last==-1 && str[0]=='9')//特殊处理需要+1的情况  
		cout << "1" ;  
	while(last+1<dot_pos)  
	{  
		cout << "0";  
		last++;  
	}  
	cout << endl;  
	//cout << ans << endl;  
	return 0;  
}  
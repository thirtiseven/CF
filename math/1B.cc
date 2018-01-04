#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <string>
#include <cstring>
using namespace std;
string t = "ZABCDEFGHIJKLMNOPQRSTUVWXYZ";
int main(){
	int n;
	cin >> n;
	while(n--)
	{
		char s[100];
		cin >> s;
		int x,y;
		if(sscanf(s,"%*c%d%*c%d",&x,&y)==2)      //判断初始形式
		{
			 string ans =  "";                  //用于记录y转化的字母形式
			 while(y / 26 >= 1)
			 {
				 ans += t[y % 26];      
				 if (y % 26 == 0)               //注意：如果能够整除，后一位需减一。
				 {
					y /= 26;
					y--;
				 }
				 else
					y /= 26;
			 }
			 if (y != 0)
				 ans += t[y % 26];       
			 reverse(ans.begin(),ans.end());          
			 cout << ans;
			 printf("%d\n",x);
		}
		else
		{
			int cnt = 0,sum = 0;
			double ans = 0;
			for( int i = 0; i < strlen(s); i++ )         //用cnt记录字母段的长度
			{
				if ( isalpha(s[i]) )
				{
					cnt++;
				}
				else            
				{
					break;
				}
			}
			for (int  i = cnt - 1,j = 0; i >= 0; i--,j++)       
			{
				if (j == 0)
					sum += s[i] - 'A' + 1;
				else
					sum += (s[i] - 'A' + 1) * (int)pow(26.0,j);     //相当于26进制
			}
			printf("R");
			for (int i = cnt; i < strlen(s); i++)
			{
				cout << s[i];
			}
			printf("C%d\n",sum);
		}
	}

	return 0;
}

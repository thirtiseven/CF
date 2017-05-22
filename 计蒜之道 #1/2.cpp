#include <iostream>
#include <cstdio>  
#include <cstring>  
#include <algorithm>  
#include <string> 
#define ll long long

int w[1000010], f[1000010];
char s[1000010], in[1000010];

void init()
{
	int i,j=0;
	int lens = strlen(s);
	for (i=1;i<lens;i++)
		{
		   while (j&&s[i]!=s[j]) j=f[j];
			if (s[i]==s[j]) j++;
		   f[i+1]=j;
		}
}

void getfill(char* s)  
{  
	memset(f,0,sizeof(f));
	for(int i=1;i<strlen(s);i++)  
	{  
		int j=f[i];  
		while(j && s[i]!=s[j])  
			j=f[j];  
		f[i+1]=(s[i]==s[j])?j+1:0;  
	}  
}  

int find(char* a,char* s)  
{  
	int ans=0;  
	init();
	int j=0;  
	int lens = strlen(s);
	int lena = strlen(a);
	for(int i=0;i<lena;i++)  
	{  
		while(j && a[i]!=s[j])  
			j=f[j];  
		if(a[i]==s[j])  
			j++;  
		if(j==lens){  
			ans++;  
		}  
	}  
	return ans;  
}

int main(int argc, char *argv[]) { 
	int n, a, b, l, r;
	std::cin >> n >> a >> b >> l >> r;
	scanf("%s",in);
	w[0] = b;
	for(int i = 1; i < n; i++) {
		w[i] = (w[i-1] + a) % n;
	}
	for(int i = 0; i < n; i++) {
		if(l <= w[i] && w[i] <= r) {
			if(w[i]%2 == 0) {
				s[i] = 'A';
			} else {
				s[i] = 'T';
			}
		} else {
			if(w[i]%2 == 0) {
				s[i] = 'G';
			} else {
				s[i] = 'C';
			}
		}
	}
	std::cout << find(s, in) << std::endl;
	return 0;
}
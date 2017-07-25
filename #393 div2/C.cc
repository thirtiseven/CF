#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n;
int p[200100];
int b[200100];
int vis[200200];
int dfs(int x)
{
	vis[x]=1;
	if(!vis[p[x]]) dfs(p[x]);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&p[i]);
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&b[i]);
		if(b[i]&1) cnt++;
	}
	int ans=0;
	if(cnt%2==0) ans++;
	cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			cnt++;
			dfs(i);
		}
	}
	if(cnt==1) cnt=0;
	printf("%d\n",ans+cnt);
}
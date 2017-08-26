#include <iostream> 
using namespace std;  
typedef long long LL;  
const int N = 2e5+10;  
const LL mod = 1e9+7;  
int n;  
int a[N];    
int vis[N];  
LL cnt;  
LL ans;  
int deps[N]; ///深度，用于记录一个环有多少条边  
  
LL Pow(LL a,LL b,LL mod)  
{  
	LL ret = 1;  
	LL A = a;  
	while(b){  
		if(b&1) ret = A*ret%mod;  
		A = A*A%mod;  
		b >>= 1;  
	}  
	return ret;  
}  
  
void dfs(int u,int dep,int fa)  
{  
	vis[u] = fa;  ///相同分量设置为同一个标记  
	deps[u] = dep;  
	if(!vis[a[u]]) dfs(a[u],dep+1,fa);  
	else{  
		if(vis[a[u]] == vis[u]){  
			ans = ans*(Pow(2,deps[u]-deps[a[u]]+1,mod)-2)%mod;  
			cnt += deps[u]-deps[a[u]]+1;  
		}  
	}  
}  
  
int main(void)  
{  
	int n;  
	ans = 1;  
	scanf("%d",&n);  
	for(int i = 1;i <= n;i++) scanf("%d",&a[i]);  
	for(int i = 1;i <= n;i++){  
		if(!vis[i]){  
			dfs(i,1,i);  
		}  
	}  
	ans = ans*(Pow(2,n-cnt,mod))%mod;  
	printf("%I64d",ans);  
	return 0;  
} 
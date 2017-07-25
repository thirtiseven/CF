#include <iostream>  
#include <cstdio>  
#include <vector>  
#include <cstring>  
#include <map>   
  
int f[200005], a[200005];  
std::vector<int> num[200005];  
 
int find(int v) {  
	if(v != f[v])  
		f[v] = find(f[v]);  
	return f[v];  
}  
void meger(int u,int v) {  
	int fu = find(u);  
	int fv = find(v);  
	if(fu != fv)  
		f[fv] = fu;  
return;}  
int main()  
{  
	int n,m,k,l,r,i,j;  
	std::cin >> n >> m >> k;  
	for(i=1; i<=n; i++) {  
		f[i] = i;  
		std::cin >> a[i];
	}  
	for(i=0; i<m; i++) {  
		std::cin >> l >> r; 
		meger(l,r);
	}  
	for(i=1;i<=n;i++) {  
		num[find(i)].push_back(a[i]); 
	}  
	int ans = 0;  
	for(i = 1; i <= n; i++) {  
		int len = num[i].size(), mmax = 0;  
 		if(len > 1) {    				
			std::map<int, int> cot;
			for(j = 0; j < len; j++) {   
				cot[num[i][j]]++;  
				mmax = std::max(mmax, cot[num[i][j]]);
			}  
			ans += (len - mmax); 
		}  
		num[i].clear(); 
	}
	std::cout << ans << std::endl; 
	return 0;  
}  
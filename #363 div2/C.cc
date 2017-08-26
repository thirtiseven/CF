#include <iostream>
#define maxn 110
#define INF 10000000 
  
int main(int argc, char *argv[]) {  
	int n, a[maxn], dp[maxn][3];
	std::cin >> n; 
	for(int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
	for(int i = 0; i < 4; i++) {
		dp[0][i]=0;  
	}
	for(int i=1;i<=n;i++) {  
		dp[i][0] = std::min(dp[i-1][0], std::min(dp[i-1][1], dp[i-1][2]))+1;  
		if(a[i]==1||a[i]==3)  
			dp[i][1]=std::min(dp[i-1][0],dp[i-1][2]);  
		else  
			dp[i][1]=INF;  
		if(a[i]==2||a[i]==3)  
			dp[i][2]=std::min(dp[i-1][0],dp[i-1][1]);  
		else  
			dp[i][2]=INF;  
		if(a[i]==0)  
		{  
			dp[i][1]=INF;  
			dp[i][2]=INF;  
		}  
	}  
	std::cout << std::min(dp[n][0],std::min(dp[n][1], dp[n][2])) << "\n";  
} 
#include <iostream>
#include <cstring>
#include <algorithm>
 
int A[100005],B[100005];
int f[505][5050];
int H[15],n,k,x,i,j;

void inc(int &a,int b){if(a<b)a=b;}

int main(int argc, char *argv[]) {
	std::cin>>n>>k;
	for(i=n*k;i--;++A[x])std::cin>>x;
	for(i=n;i--;++B[x])std::cin>>x;
	for(i=1;i<=k;)std::cin>>H[i++];

	memset(f,-1,sizeof(f));
	f[0][0]=0;
	for(i=0;i<=500;++i)
		for(j=0;j<=5000;++j)
			if(~f[i][j])
				for(x=0;x<=k;++x)
					inc(f[i+1][j+x],f[i][j]+H[x]);
	for(i=0;i<=500;++i)
		for(j=0;j<=5000;++j)
			inc(f[i][j+1],f[i][j]);
	for(i=x=0;i<100005;++i)
		x+=f[B[i]][A[i]];
	return std::cout<<x,0;
}
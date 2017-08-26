#include <iostream>
#include <algorithm>
#include <cstring>
#define N 100005
#define ll long long
#define inf 1000000

int n,k,x,a[N],l[50][N];

int check(int x){
	for(int i=0;i<x;++i) {
		bool f=1;
		for(int j=0;j<n;++j) {
			if(l[i][j]!=l[x][j]) {
				f=0;break;
			}
		}
		if(f) {
			return i;
		}
	}
	return -1;
}
int main(void){
	std::cin>>n>>k>>x;
	for(int i=0;i<n;++i){
		std::cin>>a[i];
		l[0][i]=a[i];
	}
	int pre,time=1;
	for(;time<=k;time++){
		std::sort(a,a+n);
		for(int j=0;j<n;++j){
			if(j%2==0)a[j]^=x;
			l[time][j]=a[j];
		}
		pre=check(time);
		if(pre!=-1)break;
	}
	if(k>time){
		int len=time-pre;
		int finally=(k-time)%len;
		time=pre+finally;
	} else time=k;
	int minn=inf,maxn=-inf;
	for(int i=0;i<n;++i){
		minn=std::min(minn,l[time][i]);
		maxn=std::max(maxn,l[time][i]);
	}
	std::cout<<maxn<<" "<<minn;
}
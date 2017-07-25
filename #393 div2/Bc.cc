#include <iostream>
#include <cstdio>
#include <cstring>
#define ll long long
ll n, m, k;

ll Slove(ll mid) {
	ll sum = 0;
	if(k - (mid - 1) > 1) {
		sum+=k-(mid-1)-1;
		sum+=(1+mid)*mid/2;
	}
	if(k-(mid-1)==1) {
		sum+=(1+k)*k/2;
	}
	if(k-(mid-1)<1) {
		sum+=(mid-(k-1)+mid)*k/2;
	}
	if(k+(mid-1)<n) {
		sum+=n-(k+(mid-1));
		sum+=(1+mid)*mid/2;
	}
	if(k+(mid-1)==n) {
		sum+=(1+mid)*mid/2;
	}
	if(k+(mid-1)>n) {
		sum+=(mid-(n-k)+mid)*(n-k+1)/2;
	}
	if(sum-mid<=m)return 1;
	else return 0;
}

int main()
{
	std::cin >> n >> m >> k;
		ll ans=0;
		ll l=1;
		ll r=m;
		while(r-l>=0)
		{
			ll mid=(l+r)/2;
			if(Slove(mid)==1)
			{
				ans=mid;
				l=mid+1;
			}
			else r=mid-1;
		}
	std::cout << ans<< std::endl;
}

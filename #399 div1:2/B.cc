#include <iostream>
#define LL long long

int query(LL n,LL L,LL R,LL l,LL r)
{
	if(R<l||L>r||n==0)
		return 0;
	if(n==1)
		return 1;
	LL mid=(l+r)>>1;
	return query(n/2,L,R,l,mid-1)+query(n%2,L,R,mid,mid)+query(n/2,L,R,mid+1,r);
}

int main()
{
	LL n,l,r;
	std::cin >> n >> l >> r;
	LL len=1,x=n;
	while(x>1){
		len=len*2+1;
		x>>=1;
	}
	std::cout << query(n,l,r,1,len);
	return 0;
}
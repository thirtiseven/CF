#define HAVE_STRUCT_TIMESPEC
#include<bits/stdc++.h>
using namespace std;
int lowbit(int x){
	return x&(-x);
}
const int N=1e6+5;
int c[N],a[N];
void modify(int x,int v)
{
	while(x<N)
		c[x]+=v,x+=lowbit(x);
}
int query(int x)
{
	int sum=0;
	while(x)
		sum+=c[x],x-=lowbit(x);
	return sum;
}
signed main()
{
	// file();
	int n,q;
	cin>>n>>q;
	for(int i=1; i<=n; i++)
	{
		int x;
		cin>>x;
		modify(x,1);
	}
  /*  for(int i=1;i<=n;i++)
		cout<<i<<"-"<<query(i)<<endl;*/
	while(q--)
	{
		int x;
		cin>>x;
		if(x>=1)
		{
			modify(x,1);
		}
		else
		{
			x=abs(x);
			if(query(n)<x)
				continue;
			int l=1,r=n;
			while(l<r)
			{
				int mid=(l+r)>>1;
				if(query(mid)>=x)
					r=mid;
				else
					l=mid+1;
			}
		   // cout<<x<<" "<<l<<endl;
			modify(l,-1);
		}

	}
	int ans=0;
	for(int i=1; i<=n; i++)
	{
		if(query(i))
		{
			ans=i;
			break;
		}
	}
	cout<<ans<<endl;
}
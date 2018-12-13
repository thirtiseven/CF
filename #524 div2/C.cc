#include<bits/stdc++.h>
using namespace std;
typedef int Int;
#define int long long
#define INF 0x3f3f3f3f
#define maxn 100005
int a[maxn];
Int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n,m;cin>>n>>m;
		int black=n*m/2,white=n*m-black;
		// cout<<endl;
		// cout<<white<<' '<<black<<endl;
		int x,y,xx,yy;cin>>x>>y>>xx>>yy;
		int X = xx - x + 1; int Y = yy - y + 1;
		if((x+y)%2==0){
			white+=(X*Y/2);
			black-=(X*Y/2);
		}
		else{
			white+=(X*Y-(X*Y/2));
			black-=(X*Y-(X*Y/2));
		}
		// cout<<white<<' '<<black<<endl;
		int x1=x,y1=y,xx1=xx,yy1=yy;
		cin>>x>>y>>xx>>yy;
		X = xx - x + 1; Y = yy - y + 1;
		if((x+y)%2==0){
			black+=(X*Y-(X*Y/2));
			white-=(X*Y-(X*Y/2));
		}
		else{
			black+=(X*Y/2);
			white-=(X*Y/2);
		}
		// cout<<white<<' '<<black<<endl;
		x=max(x,x1);y=max(y,y1);xx=min(xx,xx1);yy=min(yy,yy1);
		// cout<<x<<' '<<y<<' '<<xx<<' '<<yy<<endl;
		if(xx<x||yy<y){
			cout<<white<<' '<<black<<endl;
			continue;
		}
		X = xx - x + 1; Y = yy - y + 1;
		 if((x+y)%2==0){
			black+=((X*Y/2));
			white-=((X*Y/2));
		}
		else{
			black+=X*Y-(X*Y/2);
			white-=X*Y-(X*Y/2);
		}
		cout<<white<<' '<<black<<endl;
		// cout<<endl;
	}
	cin.get(),cin.get();
	return 0;
}
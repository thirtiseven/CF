
#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#define cl(x) memset(x,0,sizeof(x))
#define PI acos(-1.0)
using namespace std;
typedef long long ll;
typedef pair<double,int> abcd;
 
const int N=3005;
 
struct Point{
	int x,y; double tan;
	Point(int x=0,int y=0):x(x),y(y) { }
	void read(){
		std::cin >> x >> y;
	}
	friend Point operator - (const Point &A,const Point &B){
		return Point(A.x-B.x,A.y-B.y);
	}
	double Tan(){
		double ret=atan2(y,x);
		return ret<=0?ret+=PI:ret;
	}
	bool operator < (const Point &B) const{
		return tan<B.tan;
	}
};
 
int n,pnt; ll ans;
Point now;
abcd K[N];
int vst[N],cnt[5];
pair<Point,int> points[N],P[N],tmp[N]; 
 
inline void Solve(int ii)
{
	cl(cnt); 
	pnt=0; now=points[ii].first;
	for (int i=1;i<=n;i++) if (i!=ii) P[++pnt]=points[i];
	for (int i=1;i<=pnt;i++) P[i].first.tan=(P[i].first-now).Tan();
	sort(P+1,P+pnt+1);
	for (int i=1;i<=pnt;i++)
		if (P[i].first.y<now.y || (P[i].first.y==now.y && P[i].first.x>now.x))
			cnt[vst[i]=0]++;
		else
			cnt[vst[i]=1]++;
	for (int i=1;i<=pnt;i++)
	{
//		cnt[vst[i]]--;
		ans+=(ll)(cnt[0])*(cnt[1]);
//		cnt[vst[i]^=1]++;
	}
}
 
int main()
{
	std::cin >> n;
	for (int i=1;i<=n;i++)
		points[i].first.read(), points[i].second = 1;
	for (int i=1;i<=n;i++)
		Solve(i);
	printf("%lld\n",ans/4);
	return 0;
}
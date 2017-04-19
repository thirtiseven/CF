#include <iostream>
#include <algorithm>


typedef long long ll;
using namespace std;

ll gcd(ll a,ll b){  
	while(a%b){  
		ll temp=b;  
		b = a%b;  
		a = temp;  
	}  
	return b;  
} 

void exgcd(ll a,ll b,ll &x,ll &y,ll &g){  
	if(b==0){  
		x=1;
		y=0; 
		g=a;
		return;  
	}  
	exgcd(b,a%b,y,x,g);  
		y -= a/b*x;  
 }

int main(int argc, char *argv[]) {
	ll a,b,c,d;
	cin >> a >> b >> c >> d;
	ll w = d - b;
	ll x,y,g;
	exgcd(a,c,x,y,g);
	if(w%g){
		cout <<"-1";
	}else{
		int q=c/g;  
		x *= (w/g);  
		x=(x%q+q)%q;  
		while((w-a*x)/c>0){
			x+=q; 
		}
		cout << x * a + b<< endl;
	}
	return 0;
}
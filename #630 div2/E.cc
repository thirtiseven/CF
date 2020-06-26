#include <iostream>

using ll = long long;

const ll mod = 998244353;
struct Matrix { //矩阵类
	ll m[2][2];
	Matrix(){
		for(ll i=0;i<2;i++) for(ll j=0;j<2;j++) m[i][j]=0;
	}
	void init(){
		for(ll i=0;i<2;i++) m[i][i]=1LL;
	}
	ll *operator [](ll x){
		return m[x];
	}
};

Matrix operator *(Matrix a,Matrix b){ //矩阵乘法,多组数据可以加个全局变量len控制矩阵大小O(len^3)
	Matrix c;
	for(ll i=0;i<2;i++){
		for(ll j=0;j<2;j++){
			for(ll k=0;k<2;k++){
				c[i][j]=(c[i][j]+a[i][k]*b[k][j])%mod;
			}
		}
	}
	return c;
}

Matrix fpow(Matrix a,ll b){ //矩阵快速幂
	Matrix c;c.init();
	while(b){
		if(b&1LL) c=c*a;
		a=a*a;
		b>>=1LL;
	}
	return c;
}
Matrix ans; //答案矩阵，仅第一列有用，ans[0][0]=f(n)

ll n, m, L, R, h, t, x, y;

ll PowMod(ll a, ll b, const ll &Mod) { 
	a %= Mod;
	ll ans = 1; 
	while(b) {
		if (b & 1){
			ans = (ans * a) % Mod; 
		} 
		a = (a * a) % Mod;
		b >>= 1;
	}
	return ans; 
}

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> n >> m >> L >> R;
	t = n*m;
	h = R-L+1;
	if (n*m%2==1) {
		std::cout << PowMod(h, t, mod) << '\n';
		exit(0);
	}
	x = h/2;
	y = h-x;
	Matrix ksm;
	ksm.m[0][0] = ksm.m[1][1] = y;
	ksm.m[0][1] = ksm.m[1][0] = x;
	Matrix res = fpow(ksm, t-1);
	ll ans = res.m[1][0]*x+res.m[1][1]*y;
	ans %= mod;
	std::cout << ans << '\n';
}
#include <iostream>
#include <cstring>
using namespace std;
using ll = long long;
// ---
// O(n)求解最长回文子串
// ---
const int N = 1000005;
char a[N];
char s[N], str[N << 1];
int p[N << 1];

void Manacher(char s[], int n)
{
	str[0] = '$', str[1] = '#';
	for (int i = 0; i < n; i++) str[(i << 1) + 2] = s[i], str[(i << 1) + 3] = '#';
//	std::cout << str << '\n';
	n = 2 * n + 2;
	str[n] = 0;
	int mx = 0, id;
//	for (int i = 1; i < n; i++) std::cout << i << " \n"[i==n-1];
//	for (int i = 1; i < n; i++) std::cout << str[i] << " \n"[i==n-1];
	for (int i = 1; i < n; i++)
	{
		p[i] = mx > i ? min(p[2 * id - i], mx - i) : 1;
		while (str[i - p[i]] == str[i + p[i]]) p[i]++;
		if (p[i] + i > mx) mx = p[i] + i, id = i;
//		std::cout << p[i] << " \n"[i==n-1];
//		std::cout << str[i] << ' ' << p[i] << "\n";
	}
}

int t;

bool check(int x, int y) {
	int l = x*2+2, r = y*2+2;
	int mid = (l+r)/2;
//	std::cout << x << ' ' << y << ' ' << mid << ' ' << p[mid] << ' ' << (y-x)+1 << '\n';
	if (p[mid]-1 >= (y-x)+1) {
//		std::cout << p[mid]-1 << ' ' << (y-x)+1 << '\n';
		return true;
	}
	return false;
}

int main(int argc, char *argv[]) {  
	ios::sync_with_stdio(false);
	cin.tie(0); 
	cin >> t;
	while (t--) {
		cin >> a;
		int xx = strlen(a);
//		std::cout << "xx " << xx << '\n';
		Manacher(a, xx);
		if (check(0, xx-1)) {
			cout << a << '\n';
		} else {
			int l = 0, r =xx-1, left = xx;
			while (a[l] == a[r]) {
				l++, r--, left -= 2;
			}
			int maxx1 = 0, maxx2 = 0;
			for (int i = 0; i < left; i++) {
				if (check(l, l+i)) {
					maxx1 = i+1;
				}
			}
			for (int i = 0; i < left; i++) {
				if (check(r-i,r)) {
					maxx2 = i+1;
				}
			}
			if (maxx1 >= maxx2) {
				for (int i = 0; i < l; i++) {
					cout << a[i];
				}
				for (int i = l; i < l+maxx1; i++) {
					cout << a[i];
				}
				for (int i = r+1; i <xx; i++) {
					cout << a[i];
				}
				cout << '\n';
			} else {
				for (int i = 0; i < l; i++) {
					cout << a[i];
				}
				for (int i = r-maxx2+1; i <= r; i++) {
					cout << a[i];
				}
				for (int i = r+1; i <xx; i++) {
					cout << a[i];
				}
				cout << '\n';
			}
		}
	}
}
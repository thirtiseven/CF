#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

int gcd(int a, int b)
{
	return b ? gcd(b, a % b) : a;
}

void extend_Euclid(int a, int b, int &x, int &y)
{
	if(b == 0)
	{
		x = 1;
		y = 0;
		return;
	}
	extend_Euclid(b, a % b, x, y);
	int tmp = x;
	x = y;
	y = tmp - (a / b) * y;
}

int main()
{
	int a, b, n;
	scanf("%d%d%d",&n,&a,&b);
	int d = gcd(a, b);
	if(n % d != 0) {
		std::cout << "NO\n";
		return 0;
	}
	a /= d;
	b /= d;
	n /= d;
	int x, y;
	extend_Euclid(a, b, x, y);
	int tx = x * n;
	tx = (tx % b + b) % b;
	int ty = (n - a * tx) / b;
	if(ty < 0) ty = -ty;
	y *= n;
	y = (y % a + a) % a;
	x = (n - b * y) / a;
	if(x < 0) x = -x;
	if(x + y > tx + ty)
	{
		x = tx;
		y = ty;
	}
	printf("YES\n%d %d\n",x,y);
	return 0;
}

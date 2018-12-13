#include<cstdio>
using namespace std;
const int maxn = 200005;
char s[maxn];
int flag, len;
int main()
{
	scanf("%d%s", &len, s);
	if (len == 1) return puts(""), 0;
	for (int i = 1; i < len; i++) {
		if (flag) { printf("%c", s[i]); continue; }
		if (s[i] < s[i - 1]) {
			flag = 1;
			printf("%c", s[i]);
		}
		else printf("%c", s[i - 1]);
	}
	return 0;
}
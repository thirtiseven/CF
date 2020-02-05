#include <iostream>
#include <string>

std::string a, b, ans;

int main(int argc, char *argv[]) {  
	std::cin >> a >> b;
	int cur = 0;
	int c1 = 0, c2 = 0;
	ans = "";
	while (c1 < a.length() && c2 < b.length()) {
		std::cout << c1 << ' ' << c2 << '\n';
		if (a[c1] == '(' && b[c2] == '(') {
			ans += "(";
			c1++;
			c2++;
			cur++;
		} else if (a[c1] == ')' && b[c2] == ')') {
			if (cur > 0) {
				ans += ")";
				cur--;
			} else {
				ans += "()";
			}
			c1++;
			c2++;
		} else if (a[c1] == '(' && b[c2] == ')') {
			if (cur > 0) {
				ans += ")";
				c2++;
				cur--;
			} else {
				ans += "(";
				c1++;
				cur++;
			}
		} else if (a[c1] == ')' && b[c2] == '(') {
			if (cur > 0) {
				ans += ")";
				c1++;
				cur--;
			} else {
				ans += "(";
				c2++;
				cur++;
			}
		}
	}
	while (c1 < a.length()) {
		if (a[c1] == '(') {
			ans += "(";
			cur++;
		} else {
			if (cur > 0) {
				ans += ")";
				cur--;
			} else {
				ans += "()";
			}
		}
		c1++;
	}
	while (c2 < b.length()) {
		if (b[c2] == '(') {
			ans += "(";
			cur++;
		} else {
			if (cur > 0) {
				ans += ")";
				cur--;
			} else {
				ans += "()";
			}
		}
		c2++;
	}
	for (int i = 0; i < cur; i++) {
		ans += ")";
	}
	std::cout << ans << '\n';
}
#include <iostream>
#include <string>
#include <vector>

int main(int argc, char *argv[]) {  
	int T;
	std::cin >> T;
	for (int CAS = 1; CAS <= T; CAS++) {
		int d;
		std::string p;
		std::cin >> d >> p;
		std::cout << "Case #" << CAS << ": ";
//		std::vector<char> aa[32];
		int tot[32];
		int now = 1;
		for (int i = 0; i < p.length(); i++) {
//			aa[i] = aa[i-1];
//			if (p[i-1] == 'C') aa[i].push_back(i-1);
			tot[i] = tot[i-1];
			if (p[i] == 'C') {
				now *= 2;
			} else {
				tot[i] += now;
			}
		}
		if (tot[p.length()-1] <= d) {
			std::cout << "0\n";
			goto end;
		} else {
//			std::cout << tot[p.length()-1] << '\n';
			int ans = 0;
			while (tot[p.length()-1] > d) {
//				std::cout << tot[p.length()-1] << ' ' << p << '\n';
				for (int i = p.length()-1; i > 0; i--) {
					if (p[i-1] == 'C' && p[i] == 'S') {
						std::swap(p[i-1], p[i]);
						ans++;
						int mm = (tot[i] - (i>=2?tot[i-2]:0))/2;
						for (int j = i; j < p.length(); j++) {
							tot[j] -= mm;
						}
						break;
					}
					if (i == 1) {
						std::cout << "IMPOSSIBLE\n";
						goto end;
					}
				}
			}
			std::cout << ans << '\n';
			goto end;
		}
		end:;
	}
}
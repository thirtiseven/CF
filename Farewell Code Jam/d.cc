#include <iostream>
#include <string>
#include <cmath>

using ll = long long;

int main() {
    int T;
    ll n;
    std::cin >> T;
    for (int CASE = 1; CASE <= T; ++CASE) {
        std::cin >> n;
        n -= 1;
        ll mod = n % 26;
        n = n / 26 + 1;
        // OEIS A002024: k appears k times; a(n) = floor(sqrt(2n) + 1/2). 
        ll a = ll(sqrt(2 * n) + 0.5);
        ll b = a * (a - 1) / 2;
        // b = a * (a + 1) / 2 
        ll c = n - b - 1;
        ll d = c * 26 + mod;
        ll e = d / a;
        // std::cout << "a: " << a << '\n';
        // std::cout << "b: " << b << '\n';
        // std::cout << "c: " << c << '\n';
        // std::cout << "d: " << d << '\n';
        // std::cout << "e: " << e << '\n';
        std::cout << "Case #" << CASE << ": " << char('A' + e) << std::endl;
    }
}
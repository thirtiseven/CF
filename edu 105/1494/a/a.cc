#include <algorithm>
#include <iostream>
#include <string>

std::string s;
int t;

int main(int argc, char *argv[]) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cin >> t;
  while (t--) {
    std::cin >> s;
    std::cout << s;
  }
}
import java.util.*;
import	Collections.*;

public class Untitled {
	
	
	public static void main(String[] args) {
		Map<String,List<String>> m;
		List<List<String>> ans;
	}
}

//#include <iostream>
//#include <string>
//#include <algorithm>
//#include <vector>
//#include <map>
//
//std::map<std::string, std::vector<std::string>> m;
//std::vector<std::vector<std::string>> ans;
//
//bool cmp(std::vector<std::string> a, std::vector<std::string> b) {
//	return a[0] < b[0];
//}
//
//int main(int argc, char *argv[]) {  
//	int T;
//	std::cin >> T;
//	std::string s, t;
//	while (T--) {
//		std::cin >> s;
//		t = s;
//		std::sort(t.begin(), t.end());
//		m[t].push_back(s);
//	}
//	for (auto it: m) {
//		std::sort(it.second.begin(), it.second.end());
//		ans.push_back(it.second);
//	}
//	std::sort(ans.begin(), ans.end(), cmp);
//	for (auto it: ans) {
//		std::cout << it[0];
//		for (int i = 1; i < it.size(); i++) {
//			std::cout << ',' << it[i];
//		}
//		std::cout << '\n';
//	}
//}
// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	getline(cin, s);
	
	vector<pair<int, char>> letters;

	for(char c : s) {
		auto exist = [](vector<pair<int, char>>& v, char ch) {
			auto it = find_if(v.begin(), v.end(), [ch](pair<int, char> p) {
				return p.second == ch;
			});

			if(it != v.end()) {
				it->first++;
			}
			else {
				v.push_back({1, ch});
			}
    	};

    	exist(letters, c);	
	}

	sort(letters.begin(), letters.end());

	for(pair<int, char> p : letters) {
		cout << p.second << " : " << p.first << "\n";
	}
}

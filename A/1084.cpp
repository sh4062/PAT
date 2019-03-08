#include <bits/stdc++.h>
using namespace std;
unordered_map<char, bool> m1, m2;
vector<char> res;
string a, b;
int main() {
	cin >> a >> b;
	for(int i = 0; i < b.length(); ++i) m1[b[i]] = true;
	for(int i = 0; i < a.length(); ++i) if(!m1.count(a[i]) && !m2.count(toupper(a[i]))) {
		m2[toupper(a[i])] = true;
		res.push_back(toupper(a[i]));
	}
	for(int i = 0; i < res.size(); ++i) printf("%c", res[i]);
	return 0;
}

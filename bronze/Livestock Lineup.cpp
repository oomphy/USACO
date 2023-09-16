// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

void dfs(map<string, vector<string>>& graph, map<string, bool>& visited, string curr) {
	if(visited[curr]) return;
	cout << curr << endl;
	visited[curr] = true;
	for(int i{}; i < graph[curr].size(); ++i) {
		dfs(graph, visited, graph[curr][i]);
	}

	return;
}


int main() {
	freopen("lineup.in", "r", stdin);
	freopen("lineup.out", "w", stdout);
	vector<string> v = {"Bessie", "Buttercup", "Belinda", "Beatrice", "Bella", "Blue", "Betsy", "Sue"};
	sort(v.begin(), v.end());
	map<string, bool> ye;
	for(int i{}; i < v.size(); ++i) {
		ye[v[i]] = false;
	}

	map<string, vector<string>> m;

	int T; cin >> T;
	while(T--) {
		vector<string> temp;
		int t = 0;
		while(t < 2) {
			string s; cin >> s;
			if(s[0] >= 'A' and s[0] <= 'Z') {
				temp.push_back(s);
				++t;
			}
		}

		m[temp[0]].push_back(temp[1]);
		m[temp[1]].push_back(temp[0]);
	
	}
	for(int i{}; i < v.size(); ++i) {
		if(m[v[i]].size() == 0) {
			m[v[i]] = {};
		}

	vector<string> k;
	for(auto it = m.begin(); it != m.end(); ++it) {
		if(it -> second.size() == 0 or it -> second.size() == 1) {
			k.push_back(it -> first);
		}
	}

	sort(k.begin(), k.end());
	for(int i{}; i < k.size(); ++i) {
		if(!ye[k[i]]) {
			dfs(m, ye, k[i]);
		}
	}
}

// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(X)   (X).begin(), (X).end()
#define test     int t;cin>>t;while(t--)
#define len(X)   (int)(X).size()
#define elif     else if
#define bignum   1e9+1
#define Int      long long

void IO(string Bessie = "") {
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);
    cout.tie(nullptr);
    if (len(Bessie)) {
        freopen((Bessie+".in").c_str(), "r", stdin);
        freopen((Bessie+".out").c_str(), "w", stdout);
     }
}

bool isConnected(vector<int>& visited) {
    int n = visited.size();

    bool ye = true;
    for(int i = 1; i < n; ++i) ye &= (visited[i] != 0);

    return ye;
}

void markPath(map<int, vector<int>>& graph, int st, vector<int>& visited) {
    if(visited[st]) return;

    if(graph[st].size() == 0) return;

    visited[st] = true;

    vector<int> temp = graph[st];

    for(int i{}; i < temp.size(); ++i) {
        if(visited[temp[i]]) continue;
        markPath(graph, temp[i], visited);
    }

    return;
}

signed main() {
	IO("closing");

    int N, M; cin >> N >> M;
    map<int, vector<int>> graph;
    for(int i{}; i < M; ++i) {
        int a, b; cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<int> blocked(N + 1);

    for(int i = 1; i <= N; ++i) {
        int node; cin >> node;
        vector<int> visited = blocked;

        markPath(graph, node, visited);

        if(isConnected(visited)) {
            cout << "YES";
        }
        else {
            cout << "NO";
        }
        cout << endl;

        blocked[node] = true;

    }
}

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

vector<int> r = {1, -1, 0, 0, 1, 1, -1, -1};
vector<int> c = {0, 0, -1, 1, -1, 1, -1, 1};

void dfs(map<int, vector<int>>& graph, int ind, int st, vector<int>& visited) {
    if(visited[st] != -1) return;

    if(graph[st].size() == 0) {
        visited[st] = ind;
        return;
    }
    
    visited[st] = ind;
    vector<int> temp = graph[st];

    for(int i{}; i < temp.size(); ++i) {
        if(visited[temp[i]] != -1) continue;

        dfs(graph, ind, temp[i], visited);
    }

    return;
}


signed main() {
	IO("fenceplan");

    int N, M; cin >> N >> M;
    vector<vector<int>> coord(N + 1, vector<int>(2));
    for(int i = 1; i <= N; ++i) cin >> coord[i][0] >> coord[i][1];

    map<int, vector<int>> graph;
    for(int i{}; i < M; ++i) {
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<int> visited(N + 1, -1);
    int ind = 1;

    for(int i = 1; i <= N; ++i) {
        if(visited[i] == -1) {
            dfs(graph, ind, i, visited);
            ++ind;
        }
    }

    // for(int i = 1; i <= N; ++i) cout << visited[i] << " ";
    // cout << endl; 

    map<int, vector<int>> m;
    for(int i = 1; i < ind; ++i) {
        vector<int> v = {INT_MIN, INT_MAX, INT_MIN, INT_MAX};
        m[i] = v;
    }

    for(int i = 1; i <= N; ++i) {
        m[visited[i]][0] = max(m[visited[i]][0], coord[i][0]);
        m[visited[i]][1] = min(m[visited[i]][1], coord[i][0]);
        m[visited[i]][2] = max(m[visited[i]][2], coord[i][1]);
        m[visited[i]][3] = min(m[visited[i]][3], coord[i][1]);
    }

    int ans = INT_MAX;
    for(auto it = m.begin(); it != m.end(); ++it) {
        // cout << "ind : " << it -> first << " ::: ";
        // for(int i{}; i < it -> second.size(); ++i) {
        //     cout << it -> second[i] << " ";
        // }
        // cout << endl;

        vector<int> temp = it -> second;

        int l = temp[0] - temp[1], b = temp[2] - temp[3];
        ans = min(ans, 2 * (l + b));
    }

    cout << ans << endl;
}


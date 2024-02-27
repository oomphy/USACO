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

int numComp(map<int, vector<int>>& graph, int st, vector<int>& visited) {
    if(graph[st].size() == 0) { visited[st] = true; return 1; }
    vector<int> temp = graph[st];
    visited[st] = true;
    int ans = 0;

    for(int i{}; i < temp.size(); ++i) {
        if(visited[temp[i]]) continue;

        ans += numComp(graph, temp[i], visited);
    }

    return ans + 1;

}

signed main() {
	IO("moocast");

    int N; cin >> N;
    map<int, vector<int>> graph;

    vector<vector<int>> v(N, vector<int>(3));
    for(int i{}; i < N; ++i) {
        cin >> v[i][0] >> v[i][1] >> v[i][2];
    }

    for(int i{}; i < N - 1; ++i) {
        for(int j = i + 1; j < N; ++j) {
            int dist_sq = (v[i][0] - v[j][0]) * (v[i][0] - v[j][0]) + (v[i][1] - v[j][1]) * (v[i][1] - v[j][1]);
            double dist = sqrt((double)dist_sq);

            if((double)v[i][2] >= dist) {
                graph[i + 1].push_back(j + 1);
            }

            if((double)v[j][2] >= dist) {
                graph[j + 1].push_back(i + 1);
            }
        }
    }


    // for(auto it = graph.begin(); it != graph.end(); ++it) {
    //     vector<int> temp = it -> second;

    //     cout << it -> first << " : ";
    //     for(int i{}; i < temp.size(); ++i) cout << temp[i] << " ";
    //     cout << endl; 
    // }

    int ans = 0;

    // vector<int> dp(N + 1);
    for(int i = 1; i <= N; ++i) {
        vector<int> visited(N + 1);
        ans = max(ans, numComp(graph, i, visited));
    }

    cout << ans << endl; 
}


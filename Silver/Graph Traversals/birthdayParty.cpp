#include<bits/stdc++.h>
using namespace std;

#define long long int;

void Solve(int p, int c);

void dfs(vector<vector<int>>& graph, vector<int>& visited, int st) {
    if(visited[st]) return;

    visited[st] = true;

    for(int i{}; i < graph.size(); ++i) {
        if(!visited[i] and graph[st][i] and graph[i][st]) {
            dfs(graph, visited, i);
        }
    }

    return;
}

bool isConnected(vector<vector<int>>& graph, vector<int>& visited, int st) {
    dfs(graph, visited, st);

    for(int i{}; i < visited.size(); ++i) {
        if(!visited[i]) return false;
    }

    return true;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int p = 100, c = 100; cin >> p >> c;
    while(p != 0 and c != 0) {
        Solve(p, c);
        cin >> p >> c;
    }
}

void Solve(int p, int c) {
    // cout << p << " " << c << endl << endl;
    vector<vector<int>> graph(p, vector<int>(p)), edges(c, vector<int>(2));
    for(int i{}; i < c; ++i) {
        int a, b; cin >> a >> b;
        edges[i][0] = a; edges[i][1] = b;

        graph[a][b] = true; graph[b][a] = true;
    }

    for(int i{}; i < c; ++i) {
        int a = edges[i][0], b = edges[i][1];

        graph[a][b] = false; graph[b][a] = false;
        vector<int> visited(p);

        if(!isConnected(graph, visited, 0)) {
            cout << "Yes" << endl;
            return;
        }

        graph[a][b] = true; graph[b][a] = true;
    }

    cout << "No" << endl;
}

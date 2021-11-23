#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("cowsignal.in", "r", stdin);
	freopen("cowsignal.out", "w", stdout);

 
int m{}, n{}, k{};

cin>>m>>n>>k;

vector<string> v(m);

for(int a{}; a<m; a++){
	cin>>v[a];
}

for(int i{}; i<m; i++){
	for(int j{}; j<k; j++){
		for(int b{}; b<n; b++){
			for(int c{}; c<k; c++){
				cout<<v[i][b];
			}
		}
	cout<<endl;
	}
}
}

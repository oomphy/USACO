#include <bits/stdc++.h>
using namespace std;

int main() {

	freopen("pails.in", "r", stdin);
	freopen("pails.out", "w", stdout);

	 int x{}, y{}, m{}, a{}, b{};
	 cin>>x>>y>>m;
	 
	 a = m/x;
	 b = m/y;

	 vector<int> v;

	 for(int i{}; i<=a; i++){
		 for(int j{}; j<=b; j++){
			 if(x*i + y*j <= m)
			 v.push_back(x*i + y*j);
		 }
	 }
	 sort(v.rbegin(), v.rend());
	 cout<<v[0];
	 
	 
	 return 0;
}

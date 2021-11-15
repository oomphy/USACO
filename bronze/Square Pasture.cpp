// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("square.in", "r", stdin);
	freopen("square.out", "w", stdout);

	 vector<int> x(4);
	 vector<int> y(4);

	  
	for(int i{}; i<4; i++){

		 cin>>x[i]>>y[i];
		  	 
	}
	 

	 int l{}, b{}, c{};
	 l = abs(*max_element(x.begin() , x.end()) - *min_element(x.begin() , x.end()));
	 b = abs(*max_element(y.begin() , y.end()) - *min_element(y.begin() , y.end()));
	 c = abs( l - b);

	 if(l > b){
		 cout<<l*(b+c);
		  
    }
    else{
	cout<<b*(l + c);
    }
    return 0;
}

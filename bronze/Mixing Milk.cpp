#include <bits/stdc++.h>

using namespace std;


int main() {
	freopen("mixmilk.in", "r", stdin);
	freopen("mixmilk.out", "w", stdout);

	 vector<int> x(3);
	 vector<int> y(3);

	 for(int i{}; i<3; i++){
		 cin>>x[i]>>y[i];
	 }

	//  for(int i{}; i<3; i++){
	// 	 cout<<x[i]<<" "<<y[i]<<endl;
	//  }

	for(int t{}; t<33; t++){
		for(int i{1}; i<3; i++){
		if(y[i] + y[i-1] > x[i]){

			y[i-1] = (y[i] + y[i-1]) - x[i];
			y[i] = x[i];
			
			  
		}
		else{
			y[i] = y[i-1] + y[i];
			y[i-1] = 0;
			
		}	

			
		}
		if(y[0] + y[2] > x[0]){

			y[2] = (y[2] + y[0]) - x[0];
			y[0] = x[0];
			
			  
		}
		else{
			y[0] = y[0] + y[2];
			y[2] = 0;
		}	

	}

	if(y[0] + y[1] > x[1]){

			y[0] = (y[0] + y[1]) - x[1];
			y[1] = x[1];
			
			  
		}
		else{
			y[1] = y[0] + y[1];
			y[0] = 0;
		}	
	 
		
		cout<<y[0]<<endl;	
		cout<<y[1]<<endl;
		cout<<y[2]<<endl;

		
		

	return 0;
}

#include<iostream>
#include<cmath>
using namespace std;

int k = 5;

int CalcularPesoMaximo(int *pavos, int n){
    int dp[n+1];
	
    dp[0] = 0;
    dp[1] = 0;
	
    for (int i=2 ; i<n+1 ; i++){
        if (abs(pavos[i-1] - pavos[i-2]) < k){
            dp[i] = pavos[i-1] + pavos[i-2] + dp[i-2];
        }
        else dp[i] = dp[i-1];
    }
	
	for(int i=0 ; i<n+1 ; i++){
		cout<<dp[i]<<" ";
	}
	cout<<endl;
	
    return dp[n];
}

int main(){
	// 3 25 18 15 4 12 6
    int pavos[] = {3, 4, 6, 12, 15, 18, 25};
    
    int n = 7;
	
	cout<<"El peso maximo es: "<<CalcularPesoMaximo(pavos, n)<<endl;
    
    return 0;
}



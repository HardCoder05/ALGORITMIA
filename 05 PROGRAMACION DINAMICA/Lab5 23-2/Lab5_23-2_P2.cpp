#include <iostream>
#include <iomanip>
using namespace std;

int minDesperdicio(int capacidad, int pesos[ ], int n) {
    int dp[n + 1][capacidad + 1];
	
    // Caso base: Para 0 productos, el desperdicio es igual a la capacidad del contenedor
    for (int j = 0; j <= capacidad; ++j) {
        dp[0][j] = j;
    }
	
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= capacidad; ++j) {
            if (pesos[i - 1] <= j) {
                dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - pesos[i - 1]]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
	
    for (int i = 0; i < n+1 ; i++) {
        for (int j = 0; j < capacidad + 1 ; j++) {
            cout<<setw(2)<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
	
    int ganancia, encontre = 0;
    for (int j=capacidad ; j>=0 ; j--){
	for (int i=n ; i>=0 ; i--){
	      if (dp[i][j] == 0){
		  ganancia = j;
		  encontre = 1;
		  break;
	      }
	}
	
	if (encontre){
	   break;
	}
    }
	
    cout<<endl<<"El contenedor mas grande con el desperdicio igual a 0 será de "<<ganancia<<" Toneladas.";
    
    return dp[n][capacidad];
}

int main() {
    int capacidad = 20;
    
	int n = 4;
	
    int pesos[n] = {3, 4, 8, 10};
	
    int desperdicio = minDesperdicio(capacidad, pesos, n);
    cout <<endl<< "El desperdicio de usar un contenedor de " << capacidad << " Toneladas será " 
	    << desperdicio << " Toneladas." << endl;
	
    return 0;
}


#include <iostream>
using namespace std;

int calcularCombinaciones(int n) {
    int dp[n + 1][3];
	
    dp[1][0] = 1;  // Una columna, sin aves
    dp[1][1] = 1;  // Una columna, con canario
    dp[1][2] = 1;  // Una columna, con agapornis
	
    // Calcular las combinaciones para cada columna adicional
    for (int i = 2; i <= n; ++i) {
        dp[i][0] = dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2];  // Sin aves en la columna actual
        dp[i][1] = dp[i - 1][0] + dp[i - 1][2];  // Canario en la columna actual
        dp[i][2] = dp[i - 1][0] + dp[i - 1][1];  // Agapornis en la columna actual
    }
	
	
	for(int i=0 ; i<n+1 ; i++){
		for(int j=0 ; j<3 ; j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
	
    // Sumar todas las combinaciones posibles para la última columna
    return dp[n][0] + dp[n][1] + dp[n][2];
}

int main() {
    int n;
	
	n = 2;
	
    int combinaciones = calcularCombinaciones(n);
    cout <<endl<< "Con " << n << " columnas, se pueden formar " << combinaciones << " combinaciones diferentes." << endl;
	
    return 0;
}


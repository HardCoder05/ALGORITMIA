#include <iostream>
#include<iomanip>
#define max 40
using namespace std;

void recorridoEnEspiral(int x, int y, int n, int m, int matriz[][max]) {
    int i, cont = 0;
	
    if (x >= n || y >= m)//Si se pasa los bordes: Caso base
        return;
         
    if(x==n-1){//condición especial, "caso base", cuando al terminar el remolino se queda con una fila
		for(i=y;i<m;i++)	
			cout << matriz[i][x] << " ";
		return;
	}
	
	if(y==m-1){//condición especial, "caso base", cuando al terminar el remolino se queda con una columna
		for(i=x;i<n;i++) cout << matriz[y][i] << " ";
		return;
	}	
	
    for (i = x; i < n - 1; i++)//nos movemos a la derecha
        cout << matriz[y][i] << " ";//se mueve las columnas y se fija la fila en y (posición inicial)
    
	for (i = y; i < m - 1; i++)//nos movemos hacia abajo
        cout << matriz[i][n - 1] << " ";//se mueve las filas y se fija la columna en n-1 (máximo del remolino)
    
	for (i = n - 1; i > x; i--)//nos movemos hacia la izquierda
        cout << matriz[m - 1][i] << " ";//se mueve las columnas y se fija la fila en m-1 (máximo del remolino)
    
	for (i = m - 1; i > y; i--)//nos movemos hacia arriba
        cout << matriz[i][x] << " ";//se mueve las filas y se fija la columna x (posición inicial)
	
    recorridoEnEspiral(x + 1, y + 1, n - 1, m - 1, matriz);//llamada recursiva para el siguiente remolino, 
											  //reducimos los máximos n y m
    										  //aumentamos x e y 
}

void recorridoEnEspiralInverso(int x, int y, int n, int m, int matriz[][max]) {
    if (n <= 0 || m <= 0) {
        return; // Caso base: matriz de tamaño cero o negativo
    }
	
    // Mover hacia la izquierda
    for (int i = x + n - 1; i >= x; i--) {
        cout << matriz[y][i] << " ";
    }
	
    // Mover hacia abajo
    for (int i = y + 1; i < y + m; i++) {
        cout << matriz[i][x] << " ";
    }
	
    // Mover hacia la derecha (si hay más de una fila)
    if (m > 1) {
        for (int i = x + 1; i < x + n; i++) {
            cout << matriz[y + m - 1][i] << " ";
        }
    }
	
    // Mover hacia arriba (si hay más de una columna)
    if (n > 1) {
        for (int i = y + m - 2; i > y; i--) {
            cout << matriz[i][x + n - 1] << " ";
        }
    }
	
    // Llamada recursiva para el submatriz interior
    recorridoEnEspiralInverso(x + 1, y + 1, n - 2, m - 2, matriz);
}

int main() {
    int i, j, cont = 0, flag;
    int x = 0, y = 0, n = 5, m = 5;
    int alma[max][max];
	
    for (j = 0; j < m; j++)
        for (i = 0; i < n; i++)
            alma[j][i] = ++cont;
	
	for(int k=0 ; k<m ; k++){
    	for(int l=0 ; l<n ; l++){
    		cout<<setw(2)<<alma[k][l]<<" ";
		}
		cout<<endl;
	}        
            
	cout<<endl<<"Recorrido espiral: ";
    recorridoEnEspiral(x, y, n, m, alma);
    
    cout<<endl<<"Recorrido espiral inverso: ";
	recorridoEnEspiralInverso(0, 0, n, m, alma);
    
    return 0;
}


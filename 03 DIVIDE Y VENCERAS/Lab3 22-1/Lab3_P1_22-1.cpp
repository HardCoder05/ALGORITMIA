#include <iostream>
#define N 8
using namespace std;

int mayor(int izq,int der,int centro){
	if (izq>=der && izq>=centro){
		return izq;
	}
	else {
		if (der>=izq && der>=centro){
			return der;
		}
		else {
			return centro;
		}
	}
}

int cuenta(int arreglo[N], int inicio, int medio, int fin){
	int cuentaIzq = 1;
	/*Izquierda*/
	for (int i=medio; i>inicio; i--){
		if (arreglo[i-1]<arreglo[i]){
			cuentaIzq++;
		}
		else
			break;
	}
	
	/*Derecha*/
	int cuentaDerecha = 1;
	for (int i=medio+1; i<fin; i++){
		if (arreglo[i]<arreglo[i+1]){
			cuentaDerecha++;
		}
		else
			break;
	}
	
	if (arreglo[medio]<arreglo[medio+1]){
		return cuentaIzq + cuentaDerecha;
	}
	
	return 1;
}

int cuentaConsecutivos(int arreglo[N],int inicio,int fin){
	if (inicio==fin){
		return 1;
	}
	int medio = (inicio+fin)/2;
	int izq = cuentaConsecutivos(arreglo,inicio,medio);
	int der = cuentaConsecutivos(arreglo,medio+1,fin);
	int centro = cuenta(arreglo,inicio,medio,fin);
	return mayor(izq,der,centro);
}

int main(){
	int arreglo[8] = {10, 20, 15, 10, 12, 10, 13, 18};
	cout << "La cantidad maxima de dias es: " << cuentaConsecutivos(arreglo,0,N-1);
	return 0;
}

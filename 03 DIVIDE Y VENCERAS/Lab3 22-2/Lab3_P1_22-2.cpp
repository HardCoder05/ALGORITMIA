#include <iostream>
#include<iomanip>
using namespace std;

void divideYVenceras(int evaluaciones[], int inicio, int fin, int& menorPeso, int& inicioMenor, int& finMenor) {
    if (inicio == fin) {
        menorPeso = evaluaciones[inicio];
        inicioMenor = inicio;
        
        for(int i=inicio+1 ; i<30 ; i++){
        	if(evaluaciones[inicio] == evaluaciones[i]){
        		fin = i;
			}else{
				break;
			}
		}
        
        finMenor = fin;
        return;
    }
	
    int mitad = (inicio + fin) / 2;
    
	int menorPesoIzquierda, inicioMenorIzquierda, finMenorIzquierda;
    divideYVenceras(evaluaciones, inicio, mitad, menorPesoIzquierda, inicioMenorIzquierda, finMenorIzquierda);
    
	int menorPesoDerecha, inicioMenorDerecha, finMenorDerecha;
    divideYVenceras(evaluaciones, mitad + 1, fin, menorPesoDerecha, inicioMenorDerecha, finMenorDerecha);
	
    // Combinar resultados
    menorPeso = min(menorPesoIzquierda, menorPesoDerecha);
	
    // Encontrar el rango del peso mínimo
    if (menorPesoIzquierda == menorPeso) {
        inicioMenor = inicioMenorIzquierda;
        finMenor = finMenorIzquierda;
    } else {
        inicioMenor = inicioMenorDerecha;
        finMenor = finMenorDerecha;
    }
}

int main() {
    int evaluaciones[30] = {98, 95, 92, 89, 91, 92, 89, 89, 92, 93, 94, 92, 91, 90, 88, 88, 88, 89, 
		90, 91, 88, 88, 90, 90, 92, 89, 90, 88, 90, 91};
	int menorPeso, inicioMenor, finMenor;
    
    divideYVenceras(evaluaciones, 0, 29, menorPeso, inicioMenor, finMenor);
	
	for(int i=0 ; i<30 ; i++){
		cout<<setw(2)<<evaluaciones[i]<<" ";
	}
	
	cout<<endl;
	
	for(int i=0 ; i<30 ; i++){
		cout<<setw(2)<<i+1<<" ";
	}
	
	cout<<endl;
    cout<< endl << "El menor peso fue de " << menorPeso << ". El rango de días en que lo obtuvo fue del " << inicioMenor + 1 << " al " << finMenor + 1 << "." << endl;
	
    return 0;
}


#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

void cargabin(int num, int cromo[], int n) {
    int res, i = 0;
    for (int k = 0; k < n; k++) cromo[k] = 0;
    while (num > 0) {
        res = num % 2;
        num = num / 2;
        cromo[i] = res;
        i++;
    }
}

bool esValido(int cromo[8], int predecesores[8][3], int n) {
    for (int i = 0; i < n; i++) {
        if (cromo[i] == 1) {
            for (int j = 0; j < 3; j++) {
                if (predecesores[i][j] != -1 && cromo[predecesores[i][j] - 1] == 0) {
                    return false;
                }
            }
        }
    }
    return true;
}

int main() {
    int n = 8, presupuesto = 250, mComb, mGanancia = 0;
    int proyectos[8][2] = {{80, 150}, {20, 80}, {100, 300}, {100, 150}, {50, 80}, {10, 50}, {50,120}, {50,150}};
    int predecesores[8][3] = {{-1, -1, -1}, {-1, -1, -1}, {1, 2, -1}, {-1, -1, -1}, {-1, -1, -1}, 
		{2, -1, -1}, {6, -1, -1}, {6, -1, -1}};
    int cromo[8];
	
    int opcion = (int)pow(2, n);
	
    for (int i = 0; i < opcion; i++) {
        int pParcial = 0;
        int ganancia = 0;
        cargabin(i, cromo, n);
		
        if (esValido(cromo, predecesores, n)) {
            for (int j = 0; j < n; j++) {
                pParcial += cromo[j] * proyectos[j][0];
                ganancia += cromo[j] * proyectos[j][1];
            }
			
            if (mGanancia < ganancia && pParcial <= presupuesto) {
                mGanancia = ganancia;
                mComb = i;
            }
        }
    }
	
    cout << "La maxima ganancia es: " << mGanancia << endl <<endl;
    cargabin(mComb, cromo, n);
	
    int i = 1;
    for (int j = 0; j < n; j++) {
        if (cromo[j] * proyectos[j][0] != 0) {
        	cout<<"Costo: "<<setw(3)<<cromo[j] * proyectos[j][0]<<"  ";
            cout<<"Proyecto: "<< i << endl;
        }
        i++;
    }
    cout << endl;
    
    i=1;
    for (int j = 0; j < n; j++) {
        if (cromo[j] * proyectos[j][0] != 0) {
        	cout<<"Ganancia: "<<setw(3)<<cromo[j] * proyectos[j][1]<<"  ";
            cout<<"Proyecto: "<< i << endl;
        }
        i++;
    }
    cout << endl;
	
    return 0;
}


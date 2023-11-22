#include <iostream>
#include<cmath>
#define N 9
#define M 5
#define MOV 8
using namespace std;

/*Defino una variable global para el arreglo de movimientos*/
int movimientos[MOV][2];

//no interesa
void generaCampo(char campo[N][M],int filas,int columnas){
	for (int i=0; i<filas; i++){
		for (int j=0; j<columnas; j++){
			campo[i][j] = '0';
		}
	}
}

//no interesa
void cargarMinas(char campo[N][M]){
	campo[0][4] = '*';
	campo[2][2] = '*';
	campo[4][1] = '*';
	campo[4][2] = '*';
	campo[4][4] = '*';
	campo[5][1] = '*';
	campo[5][2] = '*';
	campo[5][4] = '*';
	campo[6][0] = '*';
	campo[6][1] = '*';
	campo[6][3] = '*';
	campo[7][0] = '*';
	campo[7][1] = '*';
	campo[7][2] = '*';
	campo[7][3] = '*';
	campo[8][0] = '*';
}

void descubrirMinas(char campo[N][M],char minas[N][M],int filas,int columnas,int xInicio,int yInicio){
	/*Voy a recorrer los 8 movimientos*/
	for (int i=0; i<MOV; i++){
		int xMov = xInicio + movimientos[i][0];
		int yMov = yInicio + movimientos[i][1];
		if (xMov<filas && yMov<columnas && xMov>=0 && yMov>=0){
			if (campo[xMov][yMov]=='*'){
				minas[xMov][yMov]='*';
			}
		}
	}
}

//no interesa
void imprimeCampo(char campo[N][M],int filas, int columnas){
	for (int i=0; i<filas; i++){
		for (int j=0; j<columnas; j++){
			cout << campo[i][j] << ' ';
		}
		cout << endl;
	}
}


int cuentaPasos(char campo[N][M],char minas[N][M], int filas,int columnas,int xInicio,int yInicio,int xFin,int yFin){
	/*Como siempre debo evaluar el menor de los 3, voy a colocar un valor grande a los 3
	  por si alguno no se ejecuta*/
	int derecha=999999, abajo=999999, diagonal=999999, total;
	descubrirMinas(campo,minas,filas,columnas,xInicio,yInicio);
	if (xInicio==xFin-1 && yInicio==yFin-1){
		return 0; /*No Contabilizo el ultimo paso porque estoy contando el paso del 0,0*/
	}
	/*Evaluemos el movimiento a la derecha*/
	if (yInicio<columnas-1 && campo[xInicio][yInicio+1]!='*'){
		derecha = cuentaPasos(campo,minas,filas,columnas,xInicio,yInicio+1,xFin,yFin);
	}
	/*Evaluemos el movimiento abajo*/
	if (xInicio<filas-1 && campo[xInicio+1][yInicio]!='*'){
		abajo = cuentaPasos(campo,minas,filas,columnas,xInicio+1,yInicio,xFin,yFin);
	}
	/*Evaluemos el movimiento en diagonal*/
	if (xInicio<filas-1 && yInicio<columnas-1 && campo[xInicio+1][yInicio+1]!='*'){
		diagonal = cuentaPasos(campo,minas,filas,columnas,xInicio+1,yInicio+1,xFin,yFin);
	}
	if (derecha<abajo && derecha<diagonal){
		total = 1 + derecha;
	}
	else {
		if (abajo<derecha && abajo<diagonal){
			total = 1 + abajo;
		}
		else {
			total = 1 + diagonal;
		}
	}
	return total;
}

//revisar los movimientos diagonales
void inicializarMovimientos(){
	movimientos[0][0] = -1; movimientos[0][1] = 0;
	movimientos[1][0] = 1; movimientos[1][1] = 0;
	movimientos[2][0] = 0; movimientos[2][1] = -1;
	movimientos[3][0] = 0; movimientos[3][1] = 1;
	movimientos[4][0] = -1; movimientos[4][1] = -1;
	movimientos[5][0] = -1; movimientos[5][1] = 1;
	movimientos[6][0] = 1; movimientos[6][1] = -1;
	movimientos[7][0] = 1; movimientos[7][1] = 1;
}

int main(){
	char campo[N][M], minas[N][M];
	int xInicio=0, yInicio=0, xFin = 9, yFin=5, numPasos;
	//entrada de datos
	inicializarMovimientos();
	generaCampo(campo,N,M);
	generaCampo(minas,N,M);
	cargarMinas(campo);
	imprimeCampo(campo,N,M);
	//aqui esta lo interesante
	numPasos = cuentaPasos(campo,minas,N,M,xInicio,yInicio,xFin,yFin);
	cout << endl << "La cantidad minima de pasos es: " << numPasos << endl;
	cout << endl << "Las minas descubiertas son: " << endl;
	imprimeCampo(minas,N,M);	
	return 0;
}

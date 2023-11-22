#include <iostream>
#include <iomanip>
#define n 9
#define m 5
using namespace std;

int mov[4][2];
int carga = 29;
int parcial = 0;

void generarMov(){
    mov[0][0] = -1; mov[0][1] = 0;
    mov[1][0] = 0; mov[1][1] = 1;
    mov[2][0] = 1; mov[2][1] = 0;
    mov[3][0] = 0; mov[3][1] = -1;
}

int validarMov(int nx,int ny,int recorrido[n][m]){
    return nx>=0 and ny>=0 and nx<n and ny<m and recorrido[nx][ny] == 0;
}

int hallarRuta(int pesos[n][m],int recorrido[n][m],int x,int y,int &parcial,int cont){
    if(parcial == carga){
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(recorrido[i][j] > 0 and pesos[i][j] > 0){
                    cout<<setw(2)<<pesos[i][j]<<" ";
                }else{
                    cout<<setw(2)<<"0"<<" ";
                }
            }
            cout<<endl;
        }
        
        cout<<endl;
        
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                cout<<setw(2)<<recorrido[i][j]<<" ";
            }
            cout<<endl;
        }
        
        return 1;
    }
    
    for(int i=0 ; i<4 ; i++){
        int nx = x + mov[i][0];
        int ny = y + mov[i][1];
        
        if(validarMov(nx, ny, recorrido)){
            parcial += pesos[nx][ny];
            recorrido[nx][ny] = cont;
            
            if(parcial <= carga){
                if(hallarRuta(pesos, recorrido, nx, ny, parcial, cont+1)) return 1;
            }
            
            recorrido[nx][ny] = 0;
            parcial -= pesos[nx][ny];
        }
    }
    
    return 0;
}

int hallarRutaMaxMov(int pesos[n][m],int recorrido[n][m],int x,int y,int &parcial,
    int cont,int pasosMax){
    if(parcial==carga){
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                cout<<setw(2)<<recorrido[i][j]<<" ";
            }
            cout<<endl;
        }
        
        cout<<endl;
        
        //return 1;
        return 0;
    }
    
    if(pasosMax==0) return 0;
    
    for(int i=0 ; i<4 ; i++){
        int nx = x + mov[i][0];
        int ny = y + mov[i][1];
        
        if(validarMov(nx, ny, recorrido)){
            parcial += pesos[nx][ny];
            recorrido[nx][ny] = cont;
            
            if(parcial <= carga){
                if(hallarRutaMaxMov(pesos, recorrido, nx, ny, parcial, cont+1,
                    pasosMax-1)) return 1;
            }
            
            recorrido[nx][ny] = 0;
            parcial -= pesos[nx][ny];
        }
    }
    
    return 0;
}

int main(int argc, char** argv) {
    int pesos[n][m] = { {0, 5, 0 , 5, 4},
                        {0, 10, 0 , 7, 2},
                        {0, 7, 0 , 15, 10},
                        {0, 0, 0 , 0, 0},
                        {8, 0, 6, 8, 0},
                        {12, 0, 10, 15, 0},
                        {0, 0, 20, 5, 0},
                        {0, 0, 0 , 0, 0},
                        {8, 8, 0 , 0, 0}};
    
    int recorrido[n][m];
    
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            recorrido[i][j] = 0;
        }
    }
    
    generarMov();
    
    recorrido[0][0] = 1;
    //parte a
    if(hallarRuta(pesos, recorrido, 0, 0, parcial, 2)){
        cout<<endl<<"Hay ruta"<<endl;
        
        cout<<endl<<"Con menos pasos: "<<endl;
        
        parcial = 0;
        
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                recorrido[i][j] = 0;
            }
        }
        
        recorrido[0][0] = 1;
        //parte b
		if(!hallarRutaMaxMov(pesos, recorrido, 0, 0, parcial, 2, 9)){
            cout<<"Hay rutas"<<endl;
        }
    }else{
        cout<<"NO hay ruta"<<endl;
    }
    
    return 0;
}


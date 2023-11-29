#include <iostream>
#include <iomanip>
using namespace std;
#define n 5
#define c 4

int mov[2][2];

void generaMov(int mov[2][2]){
    mov[0][0] = 0; mov[0][1] = 1;
    mov[1][0] = 1; mov[1][1] = 0;
}

int evaluarMov(int solu[][n],int nuevoX,int nuevoY){
    return solu[nuevoX][nuevoY] == 0 and nuevoX >= 0 and nuevoX < n and 
            nuevoY >= 0 and nuevoY < n;
}

int despacha(int pedido[][2],int almacen[n][n],char tipo[n][n],
    int solu[n][n],int visitado[c],int iniX,int iniY){
    
    if(visitado[0] == 1 and visitado[1] == 1 and visitado[2] == 1 and 
        visitado[3] == 1){
        //parte b
        cout<<"Las ubicaciones del pedido son las siguientes: "<<endl;
        
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<n ; j++){
                if(solu[i][j] > 0){
                    cout<<setw(3)<<solu[i][j]<<"("<<tipo[i][j]<<")";
                }else{
                    cout<<setw(5)<<solu[i][j]<<" ";
                }
            }
            cout<<endl;
        }
        
        return 1;
    }
    
    int nuevoX, nuevoY;
    //2 movimientos
    for(int i=0 ; i<2; i++){
        nuevoX = iniX + mov[i][0];
        nuevoY = iniY + mov[i][1];
        
        if(evaluarMov(solu, nuevoX, nuevoY)){
            for(int j=0 ; j<4 ; j++){
                if(pedido[j][0] == almacen[nuevoX][nuevoY] and 
                    char(pedido[j][1]) == tipo[nuevoX][nuevoY] and 
                    visitado[j] == 0){
                    visitado[j] = 1; //pedido atendido
                    solu[nuevoX][nuevoY] = almacen[nuevoX][nuevoY];
                    
                    if(despacha(pedido, almacen, tipo, solu, visitado, 
                        nuevoX, nuevoY)){
                        return 1;
                    }
                    
                    visitado[j] = 0; //desmarco
                    solu[nuevoX][nuevoY] = 0;
                }else{
                    if(despacha(pedido, almacen, tipo, solu, visitado, 
                        nuevoX, nuevoY)){
                        return 1;
                    }
                }
            }  
        } 
    }
    
    return 0;   
}

int main(int argc, char** argv) {
    int pedido[c][2] = {{ 5, 'A'}, 
                         { 1, 'V'}, 
                         { 50, 'M'}, 
                         { 8, 'A'}};
    
    int visitado[c] = {0, 0, 0, 0};
    
    int almacen[n][n] = { {20, 10, 10, 25, 10},  
                          {10, 1, 10, 5, 15}, 
                          {1, 20, 50, 5, 1}, 
                          {25, 10, 8, 5, 15}, 
                          {10, 2, 8, 10, 10} };
    
    char tipo[n][n] = { {'A', 'V', 'A', 'M', 'M'},  
                        {'A', 'V', 'M', 'A', 'V'}, 
                        {'V', 'M', 'M', 'M', 'A'}, 
                        {'V', 'A', 'A', 'A', 'V'}, 
                        {'M', 'M', 'M', 'M', 'A'} };
    
    int solu[n][n];
    
    //lleno de ceros
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<n ; j++){
            solu[i][j] = 0;
        }
    }
    
    generaMov(mov);
    
    //parte a
    if(despacha(pedido, almacen, tipo, solu, visitado, 0, 0)){
        cout<<endl<<"SI se puede despachar"<<endl;
    }else{
        cout<<"NO se puede despachar"<<endl;
    }
    
    return 0;
}


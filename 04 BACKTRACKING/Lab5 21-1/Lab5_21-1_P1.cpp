#include <iostream>
using namespace std;

int ultima_sol[12] = {};

int BackTrack(int *ganancia, int peso, int pos, int n, int &max, int *solucion, int j){
    if (pos >= n){
        if (peso >= max){
            max = peso;
            
			for (int i=0 ; i<12 ; i++){
                ultima_sol[i] = solucion[i];
            }
        }
        
        return 0;
    }
	
    for (int i=pos ; i<n ; i++){
        solucion[j] = ganancia[i];
        
        BackTrack(ganancia, peso+ganancia[i], i+3, n, max, solucion, j+1);
                 
        solucion[j] = 0;
    }
}


int main(){
    int ganancia[] = {3, 6, 1, 2, 4, 5, 18, 10, 13, 7, 15, 2};
    int n = 12;
    int solucion[12] = {};
    
    int max = -1;
    int peso = 0;
    
    BackTrack(ganancia, peso, 0, n, max, solucion, 0);
    
	cout<<"El peso maximo es: "<<max<<endl;
    
    for (int i=0; ultima_sol[i]; i++){
        cout<<ultima_sol[i]<<" ";
    }
    
    cout<<endl;
    
    return 0;
}



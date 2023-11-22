#include <iostream>
#define max 6
using namespace std;

int mapa[][6]={	{0,0,0,1,0,1},
				{0,0,1,0,0,0},
				{0,1,0,0,0,1},
				{1,0,0,0,0,0},
				{0,1,0,0,0,0},
				{0,0,0,0,1,0}};

				
int robot(int x,int y,int x1,int y1,int x2,int y2,int n,int m){
	int cont=0;
	
	if(x>=n || y>=m || x<0 || y<0) return 0;
	if(mapa[x][y] && x2==0 && y2==0) cont++;
	
	if(x2==0){
		for(int i=x+1;i<n;i++) cont = cont+mapa[i][y];
		for(int i=0;i<x;i++) cont = cont+mapa[i][y];		
	}
	
	if(y2==0){
		for(int i=y+1;i<m;i++) cont = cont+mapa[x][i];
		for(int i=0;i<y;i++) cont = cont+mapa[x][i];		
	}
	
	cont += robot(x+x1, y+y1, x1, y1, x1, y1, n, m);
	
	return cont;
}

int main(){
	int n=6, m=6;
	cout << robot(3,2,0,1,0,0,n,m);
	
	return 0;
}

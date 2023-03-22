#include "leitura.h"

int main(){
    
    int t;

    t = tamanho();
    
    int **m = (int**)malloc(sizeof(int*) * t); //alocando as linhas da matriz
    
    for(int i = 0; i < t; i++){
        m[i] = (int*)malloc(sizeof(int) * t);
    }

    for(int i = 0;i < t;i++){
        for(int j = 0;j < t;j++)
            m[i][j]=0;
    }

    leitura(m, t);

    return 0;
}
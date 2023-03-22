#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void verifica(int N, int**m){
    int soma = 0;
    
    soma += m[0][0];
    m[0][0] = -1;

    int i = 0, j = 0; //i: linha j: coluna

    while(!(i == N-1 && j == N-1)){
        if(i == N-1){
            j++;
        } else if(j == 0){
            if(m[i+1][j] >= m[i][j+1]){
                i++;
            } else if(m[i][j+1] > m[i+1][j]){
                j++;
            }
        } else if(j == N-1){
            if(m[i+1][j] >= m[i][j-1]){
                i++;
            } else if(m[i][j-1] > m[i+1][j]){
                j--;
            } 
        } else {
            if(m[i+1][j] >= m[i][j+1] && m[i+1][j] >= m[i][j-1]){
                i++;
            } else if(m[i][j+1] > m[i+1][j] && m[i][j+1] > m[i][j-1]){
                j++;
            } else if(m[i][j-1] > m[i+1][j] && m[i][j-1] > m[i][j+1]){
                j--;
            }
        } 
        soma += m[i][j];
        m[i][j] = -1; 
    }
    printf("\nsoma: %d\n", soma);
}
#include <stdio.h>

void oriMatriz(int matriz[10][10], int n, int m){
    for(int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

void recFilas(int matriz[10][10], int n, int m){
    printf("\n++Recorrido por Filas++\n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) {
            printf("%d ", matriz[i][j]);
        }
    }
    printf("\n");
}

void recColumnas(int matriz[10][10], int n, int m){
    printf("\n+++Recorrido por Columnas+++\n");
    for(int j = m - 1; j >= 0; j--){
        for (int i = n - 1; i >= 0; i--){
            printf("%d ", matriz[i][j]);
        }
    }
    printf("\n");
}

void recDiagonal(int matriz[10][10], int n, int m){
    printf("\n++++Recorrido en Diagonal++++\n");
    if(n == m){
        for(int i = 0; i < n; i++){
            printf("%d ", matriz[i][i]);
        }
    }else if(n < m){
        for(int i = 0; i < n; i++){
            printf("%d ", matriz[i][i]);
        }
    }else{
        for(int i = 0; i < m; i++){
            printf("%d ", matriz[i][i]);
        }
    }
    printf("\n");
}

int main(){
    int n, m;
    int matriz[10][10];
    
    printf("Numero de filas: ");
    scanf("%d", &n);
    printf("Numero de columnas: ");
    scanf("%d", &m);
    if(n > 10 || m > 10 || n <= 0 || m <= 0){
        printf("Las dimensiones deben ser entre 1 y 10.\n");
        return 1;
    }

    printf("\nValores de la matriz %dx%d:\n", n, m);
    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            printf("Matriz[%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
    
    printf("\n+Matriz Original+\n");
    oriMatriz(matriz, n, m);   
    recFilas(matriz, n, m);
    recColumnas(matriz, n, m);
    recDiagonal(matriz, n, m);
    
    return 0;
}

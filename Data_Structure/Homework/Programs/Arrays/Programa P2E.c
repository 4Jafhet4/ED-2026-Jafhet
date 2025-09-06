#include <stdio.h>

int main() {
    //Números pares en orden inverso
    int num_p[10];
    int i;
    printf("=== PRIMER PROGRAMA ===\n");
    for (i = 0; i < 10; i++) {
        num_p[i] = (i + 1) * 2;
    }
    printf("Numeros pares en orden inverso:\n");
    for (i = 9; i >= 0; i--) {
        printf(" %d ", num_p[i]);
    }
    printf("\n");
    
    //Número de cuenta modificado
    printf("=== SEGUNDO PROGRAMA ===\n");
    int array[10] = {4, 2, 4, 0, 0, 6, 9, 5, 2};
    int p = 0;
    for (i = 0; i < 10; i++) {
        if (array[i] != 0) {
            p = i;
        }
    }  
    int valor = array[p];
    for (i = p; i >= 0; i--) {
        if (array[i] == valor) {
            array[i] = -1;
            break;
        }
    }
    printf("Numero de Cuenta (modificado):\n");
    for (i = p; i >= 0; i--) {
        printf("%d", array[i]);
    }

    return 0;
}

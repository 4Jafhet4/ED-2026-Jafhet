#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void capAlum(char ****alum, int *n, int *capacidad){
    char continuar;
    do{
        if(*n >= *capacidad){
            *capacidad *= 2;
            char ***temp = (char ***)realloc(*alum, *capacidad * sizeof(char **));
            if(temp == NULL){
                printf("No se pudo redimensionar memoria\n");
                break;
            }
            *alum = temp;
        }
        
        // Memoria para el alumno
        (*alum)[*n] = (char **)malloc(3 * sizeof(char *));
        for(int i = 0; i < 3; i++){
            (*alum)[*n][i] = (char *)malloc(25 * sizeof(char));
        }
        // Captura de datos
        printf("\n~~~ Alumno %d ~~~\n", *n + 1);
        printf("Nombre: ");
        scanf("%24s", (*alum)[*n][0]);
        printf("Edad: ");
        scanf("%24s", (*alum)[*n][1]);
        printf("Calificacion: ");
        scanf("%24s", (*alum)[*n][2]);
        (*n)++;
        
        printf("\n¿Agregar otro alumno? (s/n): ");
        scanf(" %c", &continuar);
        
    }while(tolower(continuar) == 's');
}

void calProm(char ***alum, int n){
    int sum_edad = 0;
    float sum_cal = 0;
    for(int i = 0; i < n; i++){
        sum_edad += atoi(alum[i][1]);
        sum_cal += atof(alum[i][2]);
    }
    
    int prom_edad = sum_edad / n;
    float prom_cal = sum_cal / n;
    
    printf("\n ~RESULTADOS~ \n");
    printf("Total de alumnos: %d\n", n);
    printf("Promedio de edad: %d años\n", prom_edad);
    printf("Promedio de calificacion: %.1f\n", prom_cal);
}

void impTabla(char ***alum, int n){
    printf("\n ~TABLA DE ALUMNOS~ \n");
    printf("%-20s %-5s %-12s\n", "Nombre", "Edad", "Calificacion");
    printf("%-20s %-5s %-12s\n", "-------------------", "-----", "------------");
    
    for(int i = n - 1; i >= 0; i--){
        printf("%-20s %-5s %-12s\n", alum[i][0], alum[i][1], alum[i][2]);
    }
}

void freeMemory(char ***alum, int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 3; j++){
            free(alum[i][j]);
        }
        free(alum[i]);
    }
    free(alum);
}

int main() {
    int n = 0;
    int capacidad = 2;
    char ***alum = (char ***)malloc(capacidad * sizeof(char **));
    
    if(alum == NULL){
        printf("No se pudo asignar memoria\n");
        return 1;
    }
    capAlum(&alum, &n, &capacidad);
    
    if(n > 0){
        calProm(alum, n);
        impTabla(alum, n);
    }else{
        printf("\nNo se registraron alumnos.\n");
    }
    
    freeMemory(alum, n);
    return 0;
}
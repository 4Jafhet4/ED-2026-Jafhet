#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int caracterValido(char c){
    return isupper(c);
}

char** crearMatriz(char *word, int length){
    int i, j;
    char **matriz = malloc((length + 1) * sizeof(char *));
    if (!matriz) return NULL;
    
    for(i = 0; i < length; i++){
        if(!caracterValido(word[i])){
            matriz[i] = NULL;
            continue;
        }
        
        matriz[i] = malloc((length - i + 1) * sizeof(char));
        if(!matriz[i]){
            for(j = 0; j < i; j++){
                if (matriz[j] != NULL) free(matriz[j]);
            }
            free(matriz);
            return NULL;
        }
        
        for(j = 0; j < length - i; j++){
            matriz[i][j] = word[i];
        }
        matriz[i][length - i] = '\0';
    }
    matriz[length] = NULL;
    return matriz;
}

void showMatriz(char **matriz, int length){
    int i, j;
    for(i = 0; i <= length; i++){
        if(i < length && matriz[i] == NULL){
            printf("NULL\n");
        }else if(i == length){
            printf("NULL\n");
        }else{
            for(j = 0; j < length - i; j++){
                printf("| %c ", matriz[i][j]);
            }
            printf("|\n");
        }
    }
}

int main(int argc, char *argv[]){
	int i;
    if(argc < 2){
        printf("Uso: %s <PALABRA>\n", argv[0]);
        return 1;
    }
    
    int length = strlen(argv[1]);
    char **matriz = crearMatriz(argv[1], length);
    
    if(matriz){
        showMatriz(matriz, length);
        for(i = 0; i < length; i++){
            if(matriz[i] != NULL){
                free(matriz[i]);
            }
        }
        free(matriz);
    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

void merge(int *arr, int a, int b, int c){
	int i, j, k;
	int p = b - a + 1;
	int q = c - b;
	int *L = (int *)malloc(p * sizeof(int));
	int *R = (int *)malloc(q * sizeof(int));
	
	for(i=0; i<p; i++){
		L[i] = arr[a + i];
	}
	for(j=0;j<q;j++){
		R[j] = arr[b + 1 + j];
	}
	
	i = 0;
	j = 0;
	k = a;
	
	while (i < p && j < q){
		if(L[i] <= R[j]){
			arr[k] = L[i];
			i++;
		}
		else{
			arr[k] = R[j];
			j++;
		}
		k++;
	}
	
	while (i < p){
		arr[k] = L[i];
		i++;
		k++;
	}
	
	while (j < q){
		arr[k] = R[j];
		j++;
		k++;
	}
	
	free(L);
	free(R);
}

void mergeSortR(int *arr, int a, int c){
	if(a<c){
		int b = a + (c - a) / 2;
		mergeSortR(arr, a, b);
		mergeSortR(arr, b + 1, c);
		merge(arr, a, b, c);
	}
}

void mergeSort(int *arr, int n){
	mergeSortR(arr, 0, n-1);
}

int main (int argc, char *argv[]){
	if(argc < 2){
		return 1;
	}
	
	int n = argc - 1;
	int *arr = (int *)malloc(n * sizeof(int));
	int i;
	
	for(i=0; i<n; i++){
		arr[i] = atoi (argv[i + 1]);
	}
	
	fprintf(stdout, "Original: ");
	for(i=0; i<n; i++){
		fprintf(stdout, "%d ", arr[i]);
	}
	
	printf("\n");
	
	mergeSort(arr, n);
	
	fprintf(stdout, "Ordenado: ");
	for(i=0; i<n; i++){
		fprintf(stdout, "%d ", arr[i]);
	}
	
	printf("\n");
	
	free(arr);
	return 0;
}
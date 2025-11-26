#include <stdio.h>
#include <stdlib.h>

int getM(int *arr, int n){
	int mx = arr[0];
	int i;
	for(i=1; i<n; i++){
		if(arr[i] > mx){
			mx = arr[i];
		}
	}
	return mx;
}

void countRadix(int *arr, int n, int d){
	int *salida = (int *)malloc(n * sizeof(int));
	int count[10] = {0};
	int i;
	
	for(i=0; i<n; i++){
		count[(arr[i] / d) % 10]++;
	}
	
	for(i=1; i<10; i++){
		count[i] += count[i - 1];
	}
	
	for(i=n-1; i>=0; i--){
		salida[count[(arr[i]/d)%10]-1] = arr[i];
		count[(arr[i]/d)%10]--;
	}
	
	for(i=0; i<n; i++){
		*(arr+i) =*(salida +i);
	}
	
	free(salida);
}

void radixR(int *arr, int n, int m, int d){
	if(m/d <= 0){
		return;
	}
	countRadix(arr, n, d);
	radixR(arr, n, m, d*10);
}

void radixSort(int *arr, int n){
	int m = getM(arr, n);
	radixR(arr, n, m, 1);
}

int main (int argc, char *argv[]){
	if(argc < 2){
		return 0;
	}
	int n = argc - 1;
	int *arr = (int *)malloc(n *  sizeof(int));
	int i;
	
	for(i=0; i<n; i++){
		arr[i] = atoi(argv[i+1]);
	}
	
	fprintf(stdout, "Entrada: ");
	for(i=0; i<n; i++){
		fprintf(stdout, "%d ", arr[i]);
	}
	
	printf("\n");
	
	radixSort(arr, n);
	
	fprintf(stdout, "Radix: ");
	for(i=0; i<n; i++){
		fprintf(stdout, "%d ", arr[i]);
	}
	
	printf("\n");
	free(arr);
	
	return 0;
}
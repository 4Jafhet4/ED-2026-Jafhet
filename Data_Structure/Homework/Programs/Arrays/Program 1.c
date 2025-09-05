#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int factorial(int n){
	return factRecursion(n, 1);
}
int factRecursion(int n, int a){
	if(n<0){
		return 0;
	}else if (n==0||n==1){
		return a;
	}else{
		return factRecursion(n-1, n*a);
	}
}

int main (int argc, char *argv[]){
	char *num=argv[1];
	int n=atoi(num);
	int res= factorial(n);
	printf("Factorial de %d es: %d\n",n, res);
	return 0;
}

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int factorial(int n){
	return factRecursion(n, 1);
}
int factRecursion(int n){
	if(n<0){
		return 0;
	}else if (n==0||n==1){
		return 1;
	}else{
		return n*factRecursion(n-1);
	}
}

int main (int argc, char *argv[]){
	char *num=argv[1];
	int n=atoi(num);
	int res= factorial(n);
	printf("Factorial de %d es: %d\n",n, res);
	return 0;
}

#include <stdio.h>


int main(){

	int n, b, aux;

	scanf("%d %d", &n, &b);

	aux=b;
	while(aux<n)
	{
		aux=aux*b;
	} 
	if(aux==n)
	{
		printf("sim\n");
	}
	else
	{
		printf("não\n");
	}

	return 0;
}

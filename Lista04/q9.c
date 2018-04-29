#include <stdio.h>

int main(){

	char frase[100], aux[100];
	int i, n;
	
	fgets(frase, 100, stdin);

	for(i=0, n=strlen(frase)-1; i<n; i++, n--)
	{
		aux[i]=frase[i];
		frase[i]=frase[n];
		frase[n]=aux[i];
	}

	printf("%s\n", frase);

	return 0;
	
}

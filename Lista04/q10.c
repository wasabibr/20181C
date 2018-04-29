#include <stdio.h>
#include <string.h>

int main(){

	char frase[201];
	int i=0, n=0, aux=0;
	unsigned char ascii;

	fgets(frase, 201, stdin);
	n=strlen(frase);
	
	for(ascii=65; ascii<=90; ascii++)
	{
		for(i=0; i<n; i++)
		{
			if(frase[i]==ascii)
			{
				aux++;
			}
		}
		if(aux>0)
			printf("%c: %d\n",ascii,aux);
		aux=0;
	}

	for(ascii=97; ascii<=122; ascii++)
	{
		for(i=0; i<n; i++)
		{
			if(frase[i]==ascii)
			{
				aux++;
			}
		}
		if(aux>0)
			printf("%c: %d\n",ascii,aux);
		aux=0;
	}
			
	return 0;
}

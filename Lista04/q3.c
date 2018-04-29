#include <stdio.h>
#include <string.h>

int main(){

	char frase[100];
	int i=0, n=0, aux=0;
	unsigned char ascii;

	fgets(frase, 201, stdin);
	n=strlen(frase);
	
	for(ascii=97; ascii<=122; ascii++)
	{
		for(i=0; i<n; i++)
		{
			if(frase[i]==ascii)
			{
				aux++;
			}
		}
		if(aux==0)
			printf("%c",ascii);
		aux=0;
	}
			
	return 0;
}

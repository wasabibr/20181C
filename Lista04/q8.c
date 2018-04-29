#include <stdio.h>
#include <string.h>

int main(){

	char palavra[18], letra[1], l;
	int i, j, n, cont=0;

	fgets(palavra, 18, stdin);

	n=strlen(palavra)-1;
	letra[0]=palavra[n-1];

	for(i=0; palavra[i]!='\0'; i++)
	{
		l=palavra[i];
		if(l==letra[0])
		{
			cont++;
		}
	}

	printf("%d\n", cont-1);

	return 0;
}

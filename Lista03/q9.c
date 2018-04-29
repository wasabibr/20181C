#include <stdio.h>

int main() {

	int x, i, somadiv=0;

	scanf("%d", &x);

	if(x<0)
	{
		printf("Não perfeito\n");
	}
	else
	{
		for(i=1; i<x; i++)
		{
			if(x%i==0)
			{
				somadiv=somadiv+i;
			}
		}
		if(somadiv==x)
		{
			printf("Perfeito\n");
		}
		else
		{
			printf("Não perfeito\n");
		}
	}

	return 0;
}

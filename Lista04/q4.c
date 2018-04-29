#include <stdio.h>

int main(){

	int n, i, j, vetA[10], vetN[10], cont=0, aux=0;

	scanf("%d", &n);
	for(i=0; i<n; i++)
	{
		vetA[i]=i+1;
		scanf("%d", &vetN[i]);
	}
	for(i=0; i<n; i++)
	{
		for(j=1+i; j<n; j++)
		{
			if(vetN[i]>vetN[j])
			{
				aux=vetN[i];
				vetN[i]=vetN[j];
				vetN[j]=aux;
			}
		}
	}

	for(i=0; i<n; i++)
	{	
		if(vetN[i]!=vetA[i])
		{
			cont++;
		}
	}
	if(cont>0)
	{
		printf("não");
	}
	else
	{
		if(cont==0)
		{
			printf("sim");
		}
	}

	return 0;
}

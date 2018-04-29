#include <stdio.h>

int main(){

	int n, i, cont=0, vetG[20], vetR[20];

	scanf("%d", &n);

	for(i=0; i<n; i++) // Leitura do gabarito (n notas)
	{
		scanf("%d", &vetG[i]);
	}

	for(i=0; i<n; i++) // Leituras das n respostas
	{
		scanf("%d", &vetR[i]);
	}

	for(i=0; i<n; i++)
	{	
		if(vetG[i]==vetR[i])
		{
			cont++;
		}
	}
	if(cont<1 || cont>1)
	{
		printf("%d acertos\n", cont);
	}
	else
	{
		if(cont==1)
		{
			printf("%d acerto\n", cont);
		}
	}

	return 0;
}

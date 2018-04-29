#include<stdio.h>

int main(){

	int renda, risco;
	printf("Digite a renda mensal: ");
	scanf("%d",&renda);
	if(0<=renda && renda<700)
	{
		printf("Resultado: alto risco\n");	
	}
	else
	{
		if(700<=renda && renda<3200)
		{	
			printf("Digite se o histórico de crédito é bom: ");
			scanf("%d", &risco);
			if(risco==1)
				printf("Resultado: médio risco\n");
			else
				printf("Resultado: alto risco\n");
		}
		else
		{
			if(renda>=3200)
			{
				printf("Digite se o histórico de crédito é bom: ");
				scanf("%d", &risco);
				if(risco==1)
					printf("Resultado: baixo risco\n");
				else
					printf("Resultado: médio risco\n");
				}
		}
	}



	return 0;
}


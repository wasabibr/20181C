# include <stdio.h>


int main(){

	int n, i, j, aux=0, aux2=0, cont=0, mes[20], diaschuva[20];

	scanf("%d", &n);

	for(i=0; i<n; i++)
	{
		mes[i]=i+1;
		scanf("%d", &diaschuva[i]);
	}

	for(i=0; i<n; i++)
	{
		for(j=0; j<i; j++)
		{
			if(diaschuva[i]>diaschuva[j])
			{
				aux=diaschuva[i];
				aux2=mes[i];
				diaschuva[i]=diaschuva[j];
				mes[i]=mes[j];
				diaschuva[j]=aux;
				mes[j]=aux2;
			}
		}
	}

	for(i=0, j=0; i<n-1, j<n; i++, j++)
	{	
		if(diaschuva[i]!=diaschuva[i+1])
		{
			if(diaschuva[i]==diaschuva[i+1])
			{
				printf("%d ", mes[j]);
				break;
			}
			else
			{
				printf("%d ", mes[j]);
				break;
			}
		}
		else
		{
			if(diaschuva[i]==diaschuva[i+1])
			{
				printf("%d ", mes[j]);
			}
		}
	}

		printf("%d ", diaschuva[0]);

	return 0;
}





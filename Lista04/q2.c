#include <stdio.h>

int main(){

	int n, i, cont;
	float vet[30], media=0;

	scanf("%d", &n);
	for(i=0; i<n; i++)
	{
		scanf("%f", &vet[i]);
	}
	for(i=0; i<n; i++)
	{
		media=media+vet[i];
	}
	media=media/n;
	for(i=0; i<n; i++)
	{
		if(vet[i]>=media)
		{
			cont++;
		}
	}

	printf("%d\n", cont);


	return 0;
}

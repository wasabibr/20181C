#include <stdio.h>

int main(){

	int i, n, nMenos1=1, nMenos2=1, nResultante=0;

	scanf("%d", &n);

	if(n>0 && n<=2)
	{
		nResultante=nResultante+nMenos1;	
		printf("%d", nResultante);
	}
	else
	{
		if(n>2)
		{
			for (i=3; i<=n; i++)
			{
				nResultante=nMenos1+nMenos2;
				nMenos2=nMenos1;
				nMenos1=nResultante;
			}
		}
	printf("%d\n", nResultante);
	}

	return 0;
}

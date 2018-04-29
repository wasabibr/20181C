#include <stdio.h>

int main(){

	int i, ilha[10], cont[10];

	for(i=0; i<=9; i++)
	{
		scanf("%d ", &ilha[i]);
		cont[i]=0;
	}
	
	i=0;	

	while(cont[i]!=2)
	{
		cont[i]++;
		i=ilha[i];
	}

	printf("%d\n", i);
	
	return 0;
}

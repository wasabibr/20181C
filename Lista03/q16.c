#include <stdio.h>

int main(){

	int a, b, diva=0, divb=0;

	scanf("%d %d", &a, &b);

	for(int i=1; i<a; i++)
	{
		if(a%i==0)
		{
			diva=diva+i;
		}
	}
	for(int i=1; i<b; i++)
	{
		if(b%i==0)
		{
			divb=divb+i;
		}
	}
	if(diva==b && divb==a)
	{
		printf("sim\n");
	}
	else
	{
		printf("não\n");
	}
	return 0;
}

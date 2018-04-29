#include <stdio.h>

int main(){

	int a, b, i;

	scanf("%d %d", &a, &b);

	if(a>b)
	{
		for(i=a; i>b; i--)
		{
			printf("%d ", i);			
		} 
		printf("%d\n", b);
	}
	else
	{
		for(i=a; i<b; i++)
		{
			printf("%d ", i);			
		} 
		printf("%d\n", b);		
	}

	return 0;
}

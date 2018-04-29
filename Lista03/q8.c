#include <stdio.h>

int main(){

	int a, b, i, div=0;	

	scanf("%d %d", &a, &b);
	for(i=1; i<1001; i++)
	{
		if(i%a==0 && i%b==0)
		{
			printf("%d ", i);
		}
	}
	printf("\n");
	return 0;
}

#include<stdio.h>


int main(){

	int x, n;
	scanf("%d %d", &x, &n);
	
	if(n==0)
	{
		printf("\n");
	}
	else	
	{
		for(int i=0; i<n-1; i++){
			printf("%d", x);
			printf(", ");
		}
		printf("%d\n", x);
	}

	return 0;
}

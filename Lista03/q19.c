#include <stdio.h>

int main(){

	int n, i, num, zeros=0, maior=0;

	scanf("%d", &n);

	for(i=0; i<n; i++)
	{
		scanf("%d", &num);
		if(num==0)
		{
			zeros++;
		}
		else
		{		
			if(zeros>maior)
			{
				maior=zeros;
				zeros=0;
			}
		}
		if(i==n-1 && zeros>maior)
		{
			maior=zeros;
			zeros=0;			
		}
	}
	printf("%d\n", maior);

	return 0;
}

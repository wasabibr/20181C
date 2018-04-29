#include <stdio.h>

int main(){

	int n, num, maior;

	scanf("%d %d", &n, &num);

	maior=num;
	for(int i=1; i<n; i++)
	{
		scanf("%d", &num);		
		if(num>maior)
			maior=num;
	}
	printf("%d\n", maior);

	return 0;
}

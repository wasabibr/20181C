#include <stdio.h>
#include <math.h>
 
int main() {
 
	int a, b, c;
	
	scanf("%d %d %d", &a, &b, &c);
	
	if((abs(b-c) < a && a < (b + c)) && (abs(a-c) < b && b < (a + c)) && (abs(a-b) < c && c < (a + b)))
	{
		printf("Existe\n");		
		if((a==b && a!=c) || (a==c && a!=b) || (b==c && b!=a))
			printf("Classificação: isósceles");
		else
		{
			if(a==b && b==c)
				printf("Classificação: equilátero");
			else
			{
				if(a != b && b != c && a != c)
					printf("Classificação: escaleno");	
			}
		}
	}
	else
		printf("Não existe");
				
	return 0;
}

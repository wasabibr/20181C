#include <stdio.h>
 
main() {
 
	int mes, meses[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};


	printf("Digite o mês: ");
	scanf("%d", &mes);
	printf("%d dias", meses[mes]);

	return 0;
}

	

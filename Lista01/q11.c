#include <stdio.h>

main(){
	
	int n;
	scanf("%d", &n);
	if(n%3==0 && n%5!=0 && n!=0){
		printf("Resposta: 1\n");
	}
	else
		printf("Resposta: 0\n");
	return 0;
}

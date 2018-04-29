#include <stdio.h>

main(){
	
	int A, B, C;
	scanf("%d %d %d", &A, &B, &C);
	if(A+B==C || A+C==B || B+C==A){
		printf("Resposta: 1\n");
	}
	else
		printf("Resposta: 0\n");
	return 0;
}

#include <stdio.h>

int main(){

	float p, t, nota;

	scanf("%f", &p);
	scanf("%f", &t);
		
	nota = p + (t * p)/9;

	printf("Nota: %.2f\n", nota);

	return 0;
}

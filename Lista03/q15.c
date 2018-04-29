#include <stdio.h>

int main(){

	int n, cont=0;
	float a, b, c;

	printf("Digite a quantidade de prédios: ");
	scanf("%d", &n);
	
	for(int i=0; i<n; i++){
		a=b;
		b=c;
		scanf("%f", &c);
		if(b>a && b>c){
			cont++;
		}
	}
	printf("%d\n", cont);
	
	return 0;

}

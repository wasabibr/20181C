#include <stdio.h>
#include <math.h>

main(){
	
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	printf("%f\n", c-(3*a+2*b)/(c-c*pow(a+b,2)/sqrt(b)));
	return 0;
}

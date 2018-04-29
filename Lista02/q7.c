#include <stdio.h>
 
main() {
 
	int i, num[4], maior;

	for (i=0; i<4; i++){
		scanf("%d", &num[i]);
	}
	
	maior=num[0];
	
	for (i=1; i<4; i++){
		if(maior<num[i])
			maior=num[i];
	}
	
	printf("Maior: %d", maior);
	
	return 0;
}

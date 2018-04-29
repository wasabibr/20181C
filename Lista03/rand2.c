#include <stdio.h>
#include <stdlib.h>

int main() {

	int i;
	srand(500);
	for(i = 0; i < 5; i++) {
		printf("%d ", rand());
	}

	return 0;
}

#include <stdio.h>

int main(){

	int i=0;	
	float larg, comp, largbol;
	
	scanf("%f %f %f", &larg, &comp, &largbol);

	do {
		if(larg>comp && comp>largbol)
		{
			larg=larg/2;
			i++;
		}
		else
		{
			if(comp>larg && larg>largbol)
			{
				comp=comp/2;
				i++;
			}
			else
			{
				if((comp>=larg || comp<larg) && (larg==largbol || comp==largbol))
				{
					i++;
				}
			}
		}
	} while (larg>largbol && comp>largbol);

	printf("%d\n", i);

	return 0;
}

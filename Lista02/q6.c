#include <stdio.h>
#include <stdlib.h>

int main() {
	
	int hi=0, mi=0, hf=0, mf=0, hr=0, mr=0, abs(int x), tempMin=0, auxH=0;

	printf("Digite as horas do horário inicial: ");
	scanf("%d", &hi);
	printf("Digite os minutos do horário inicial: ");
	scanf("%d", &mi);
	printf("Digite as horas do horário final: ");
	scanf("%d", &hf);
	printf("Digite os minutos do horário final: ");
	scanf("%d", &mf);

	if(mi==0)
	{
		tempMin=mf;
		mr=tempMin-(abs(tempMin/60)*60);
		auxH=(tempMin-mr)/60;
	}
	else
	{
		tempMin=mf+(60-mi);
		mr=tempMin-(abs(tempMin/60)*60);
		auxH=(tempMin-mr)/60;
	}

	if(hi==0)
	{
		hr=hf;
	}
	else
	{
		if(hi==23)
			hr=hf;
		else
		{
			if(hi>0 && hi<23)
			{
				if(hi<=hf)
					hr=hf-hi-1;
				else
					hr=hf-hi;
			}
		}
	}
	
	hr=hr+auxH;

	printf("Resultado: %dh%dmin", hr, mr);
		
	return 0;
}

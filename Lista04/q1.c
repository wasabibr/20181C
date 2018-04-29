#include <stdio.h>
#include <string.h>

int main(){

	char palavra[21];
	int i;

	scanf("%s", palavra);

	scanf("%d", &i);

	if(palavra[i]=='*')
	{
		printf("bum!\n");
	}
	else
	{
		if((palavra[i-1]=='.' && palavra[i+1]!='*') || (palavra[i-1]!='*' && palavra[i+1]=='.') || (palavra[i-1]!='.' && palavra[i+1]!='*' && palavra[i-1]!='*' && palavra[i+1]!='.'))
		{
			printf("0\n");
		}
		if((palavra[i-1]!='*' && palavra[i+1]=='*') || (palavra[i-1]=='*' && palavra[i+1]!='*'))
		{
			printf("1\n");
		}
		if(palavra[i-1]=='*' && palavra[i+1]=='*')
		{
			printf("2\n");
		}
	}

	return 0;
}

#include <stdio.h>

int main(){

	int i=0;
	char ch, vetoraz[]={"abcdefghijklmnopqrstuvwxyz"}, vetorAZ[]={"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
	
	scanf("%c", &ch);

	for(i=0;i<26;i++)
	{
		if(ch==vetoraz[i])
		{
			printf("%c\n", vetoraz[i+1]);
		}
		else if(ch==vetorAZ[i])
		{
			printf("%c\n", vetorAZ[i+1]);
		}
	}

	return 0;
}

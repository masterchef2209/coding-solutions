#include<stdio.h>
#include<string.h>
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		char str[200];
		scanf("%s",str);
		int i;
		for(i=0;i<strlen(str)/2;i+=2)
		{
			printf("%c",str[i]);
		}
		printf("\n");
	}
return 0;}
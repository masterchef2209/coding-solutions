#include<stdio.h>
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		char n[100];
		scanf("%s",n);
		int sum=0,i;
		for(i=0;n[i]!='\0';i++)
		{
			sum+=(n[i]-'0');
		}
		printf("%d\n",sum);
	}
return 0;	
}
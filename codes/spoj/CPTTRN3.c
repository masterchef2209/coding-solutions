#include<stdio.h>
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int l,c;
		int i,j;
		scanf("%d %d",&l,&c);
		for(i=0;i<l*3;i++)
		{
			for(j=0;j<=c*3;j++)
			{
				if(i%3==0)
					printf("*");
				else
				{
					if(j%3==0)
					{
						printf("*");
					}
					else
					{
						printf(".");
					}
				}
			}
			printf("\n");
		}
		for(j=0;j<=c*3;j++)
			printf("*");
		printf("\n");
	}
return 0;	
}
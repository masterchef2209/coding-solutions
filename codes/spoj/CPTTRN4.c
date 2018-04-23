#include<stdio.h>
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int l,c,h,w;
		int i,j;
		scanf("%d %d %d %d",&l,&c,&h,&w);
		for(i=0;i<=(l*(h+1));i++)
		{
			for(j=0;j<=(c*(w+1));j++)
			{
				if(i%(h+1)==0)
					printf("*");
				else
				{
					if(j%(w+1)==0)
						printf("*");
					else
						printf(".");	
				}

			}
			printf("\n");
		}
		printf("\n");
	}
return 0;
}
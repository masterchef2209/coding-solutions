#include<stdio.h>
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int l,c,h,w,i,j;
		scanf("%d %d %d %d",&l,&c,&h,&w);
		for(i=1;i<=(l+(l+1)*h);i++)
		{
			for(j=1;j<=(c+(c+1)*w);j++)
			{
				if(i%h==0)
				{
					if(j%w==0)
					{
						printf("+");
					}
					else
					{
						printf("-");
					}
				}
				else
				{
					if(j%w==0)
					{
						printf("|");
					}
					else
					{
						printf(".");
					}
				}
			}
			printf("\n");
		}
	}
return 0;	
}
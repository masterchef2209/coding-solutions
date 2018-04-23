#include<stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	int arrn[n];
	int i,j;
	for(i=0;i<n;i++)
		scanf("%d",&arrn[i]);
	int m;
	scanf("%d",&m);
	int arrm[m];
	for(i=0;i<m;i++)
		scanf("%d",&arrm[i]);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(arrn[i]==arrm[j])
			{
				printf("%d ",arrn[i]);
			}
		}
	}
return 0;	
}
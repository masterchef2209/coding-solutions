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
		int flag=0;
		for(int j=0;j<m;j++)
		{
			if(arrn[i]==arrm[j])
			{
				flag=1;
				break;
			}
		}
		if(flag==0)
			printf("%d ",arrn[i]);

	}
return 0;	
}
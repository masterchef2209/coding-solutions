#include<bits/stdc++.h>
using namespace std;

int main()
{
	int a,b;
	while(scanf("%d %d",&a,&b)!=EOF)
	{
		if(a==b)
			printf("%d\n",a);
		else
		{
			int c=(a>b)?a:b;
			printf("%d\n",c);
		}
	}
return 0;
}
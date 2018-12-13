#include<bits/stdc++.h>
using namespace std;

int dig(int a)
{
  int sum=0;
  while(a>0)
  {
    int r=a%10;
    sum+=r;
    a=a/10; 
  }
return sum;
}

int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		int x;
    	cin>>x;
		int lo=x%1000;
		int hi=x/1000;
		int lucky=abs(dig(hi)-dig(lo));
		int count=0;
		for(int i=0;i<x;i++)
		{
			int lo=i%1000;
			int hi=i/1000;
			int lu=abs(dig(hi)-dig(lo));
			if(lu<lucky)
				count++;
		}
		cout<<count<<endl;
	}
return 0;
}
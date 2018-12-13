#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	long long Bit[1601],Nib[1601],Byt[1601];
  memset(Bit,0,sizeof(Bit));
  memset(Nib,0,sizeof(Nib));
  memset(Byt,0,sizeof(Byt));
	int j=0;
	int xx[3];
	xx[0]=2;
	xx[1]=8;
	xx[2]=16;
	int i=1;
	while(i<=1600)
	{
		int k=xx[j];
		while(i<=1600 && k--)
		{
      int u=(i-1)/26;
			if(j==0)
				Bit[i]=pow(2,u);
			else if(j==1)
				Nib[i]=pow(2,u);
			else if(j==2)
				Byt[i]=pow(2,u);
			i++;
		}
		j=(j+1)%3;
	}
	while(t--)
	{
		int n;
		cin>>n;
		cout<<Bit[n]<<" "<<Nib[n]<<" "<<Byt[n]<<endl;
	}
return 0;
}
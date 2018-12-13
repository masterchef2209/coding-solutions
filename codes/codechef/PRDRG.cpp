#include<bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) 
{ 
    if (a == 0) 
        return b; 
    return gcd(b % a, a); 
} 

long long lcm(long long a,long long b)
{
  return (a*b)/gcd(a,b);
}

int main()
{
	long long num[26],den[26];
	num[0]=1;
	den[0]=1;
	num[1]=1;
	den[1]=2;
	num[2]=1;
	den[2]=4;
	for(int i=3;i<=25;i++)
	{
    long long denlcm=lcm(den[i-2],den[i-1]);
    long long tempnum=num[i-2]*(denlcm/den[i-2])+num[i-1]*(denlcm/den[i-1]);
		long long tempden=2*denlcm;
		num[i]=tempnum;
    den[i]=tempden;
	}
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		cout<<num[n]<<" "<<den[n]<<" ";
	}
return 0;
}
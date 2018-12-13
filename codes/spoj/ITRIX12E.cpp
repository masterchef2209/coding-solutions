#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector< vector<ll> > matrix;
#define MM 1000000007

matrix mul(const matrix &A,const matrix &B)
{
	matrix C(A.size(),vector<ll>(B[0].size(),0));
	for(int i=0;i<A.size();i++)
	{
		for(int j=0;j<B[0].size();j++)
		{
			for(int k=0;k<A.size();k++)
			{
				C[i][j]=(C[i][j]+A[i][k]*B[k][j])%MM;
			}
		}
	}
	return C;
}

matrix power(const matrix &A,int p)
{
	if(p==1)
		return A;
	if(p&1)
		return mul(A,power(A,p-1));
	matrix X=power(A,p/2);
	return mul(X,X);
}

bool isPrime(int n)
{
	if(n<=1)
	{
		return false;
	}
	for(int i=2;i<=sqrt(n+1);i++)
	{
		if(n%i==0)
			return false;
	}
return true;
}

int main()
{
	matrix T(10,vector<ll>(10,0));
	for(int i=0;i<10;i++)
	{
		T[0][i]=1;
	}
	for(int i=1;i<10;i++)
	{
		for(int j=1;j<10;j++)
		{
			if(isPrime(i+j))
			{
				T[i][j]=1;
			}
		}
	}
	matrix F1(10,vector<ll>(1,0));
  matrix F2(10,vector<ll>(1,3));
	F1[2][0]=1;
	F1[3][0]=1;
	F1[5][0]=1;
	F1[7][0]=1;
  F2[0][0]=4;
  F2[1][0]=4;
  F2[2][0]=4;
  F2[4][0]=4;
  F2[7][0]=2;
	int t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
    matrix Fn;
    if(n==1)
    {
      Fn=F1;
    }
    else if(n==2)
    {
      Fn=F2;
    }
    else
    {
      matrix Ti=power(T,n-2);
		  Fn=mul(Ti,F2);
    }
		ll ans=0;
    /*for(int i=0;i<10;i++)
    {
      cout<<Fn[i][0]<<" ";
    }
    cout<<endl;*/
		for(int i=0;i<10;i++)
		{
			ans=(ans+Fn[i][0])%MM;
		}
		cout<<ans<<endl;
	}
return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define MM 1000000007
typedef unsigned long long ll;
typedef vector< vector<ll> > matrix;
int m,n;
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

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		matrix F0(3,vector<ll>(1,0));
		matrix T(3,vector<ll>(3,1));
		F0[0][0]=0;
		F0[1][0]=1;
		F0[2][0]=0;
		T[0][0]=0;
		T[0][2]=0;
		T[1][2]=0;
		T[2][0]=0;
		matrix T1,T2;
		ll a1=0,a2=0;
		if(n<=1)
		{
			a1=F0[0][0];
		}
		else
		{
			T1=power(T,n-1);
			matrix X1=mul(T1,F0);
			a1=(X1[2][0]);
		}
		if(m<=1)
		{
			a2=F0[m][0];
		}
		else
		{
			T2=power(T,m);
			matrix X2=mul(T2,F0);
			a2=(X2[2][0]);
		}
		cout<<(a2-a1+MM)%MM<<endl;
	}
return 0;
}
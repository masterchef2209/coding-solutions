#include<bits/stdc++.h>
using namespace std;
#define MM 1000000007
typedef long long ll;
typedef vector< vector<ll> > matrix;
int m,n;
matrix mul(const matrix &A,const matrix &B)
{
	matrix C(m+1,vector<ll>(m+1,0));
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=m;j++)
		{
			for(int k=1;k<=m;k++)
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
		cin>>m>>n;
		matrix T(m+1,vector<ll>(m+1));
		for(int i=1;i<=m;i++)
		{
			for(int j=1;j<=m;j++)
			{
				cin>>T[i][j];
			}
		}
		T=power(T,n);
		for(int i=1;i<=m;i++)
		{
			for(int j=1;j<=m;j++)
			{
				cout<<T[i][j]<<" ";
			}
			cout<<endl;
		}
	}
return 0;
}
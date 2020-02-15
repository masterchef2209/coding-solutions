#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mod 1000000007LL
#define eb emplace_back
 
typedef vector< vector<ll> > matrix;
 
matrix mul(const matrix &A,const matrix &B)
{
	matrix C(A.size(),vector<ll>(B[0].size(),0));
	for(int i=0;i<A.size();i++)
	{
		for(int j=0;j<B[0].size();j++)
		{
			for(int k=0;k<B.size();k++)
			{
				C[i][j]+=(A[i][k]%mod * B[k][j]%mod)%mod;
				C[i][j]%=mod;
			}
		}
	}
	return C;
}
 
matrix power(const matrix &A,ll p)
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
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll t;
	cin>>t;
	matrix M(4,vector<ll>(4,0));
	M[0][0]=M[0][1]=M[0][2]=M[0][3]=M[1][1]=M[1][2]=M[2][2]=36;
	M[3][3]=1;
	matrix XX(4,vector<ll>(1,0));
	XX[0][0]=1;
	XX[2][0]=1;
	XX[3][0]=1;
	while(t--)
	{
	    ll n;
	    cin>>n;
	    if(n==0)
	    {
	        cout<<1<<endl;
	        continue;
	    }
	    matrix M1=power(M,n);
	    matrix CC=mul(M1,XX);
	    cout<<CC[0][0]<<endl;
	}
return 0;
}
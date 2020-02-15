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

ll n,b,k,x;

ll occ[15];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>b>>k>>x;
	vector<ll>bag;
	for(ll i=0;i<n;i++)
	{
		ll tmp;
		cin>>tmp;
		occ[tmp]++;
	}
	matrix M(x,vector<ll>(x,0));
	for(ll xx=0;xx<x;xx++)
	{
		for(ll i=1;i<=9;i++)
		{
			M[(xx*10+i)%x][xx]+=occ[i];
		}
	}
	
// 		for(ll i=0;i<x;i++)
// 	{
// 	    for(ll j=0;j<x;j++)
// 	    {
// 	        cout<<M[i][j]<<" ";
// 	    }
// 	    cout<<endl;
// 	}
	
	matrix M2=power(M,b);
	
// 		for(ll i=0;i<x;i++)
// 	{
// 	    for(ll j=0;j<x;j++)
// 	    {
// 	        cout<<M2[i][j]<<" ";
// 	    }
// 	    cout<<endl;
// 	}
	
	matrix M1(x,vector<ll>(1,0));
	M1[0][0]=1;
	matrix VV=mul(M2,M1);
	
// 		for(ll i=0;i<x;i++)
// 	{
// 	    for(ll j=0;j<1;j++)
// 	    {
// 	        cout<<VV[i][j]<<" ";
// 	    }
// 	    cout<<endl;
// 	}
	
	cout<< VV[k][0];
return 0;
}
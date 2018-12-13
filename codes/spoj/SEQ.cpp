#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector< vector<ll> > matrix;
#define MM 1000000000;
int k;

matrix mul(const matrix &A,const matrix &B)
{
	matrix C(k+1, vector<ll>(k+1,0));
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=k;j++)
		{
			for(int g=1;g<=k;g++)
			{
				C[i][j]=(C[i][j]+A[i][g]*B[g][j])%MM;
			}
		}
	}
return C;
}

matrix power(const matrix &T,int n)
{
	if(n==1)
		return T;
	if(n%2)
		return mul(T,power(T,n-1));
	matrix X=power(T,n/2);
	return mul(X,X);
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		cin>>k;
		vector<ll> F(k+1);
		for(int i=1;i<=k;i++)
		{
			cin>>F[i];
		}
		vector<ll> c(k+1);
		for(int i=1;i<=k;i++)
		{
			cin>>c[i];
		}
		ll n;
		cin>>n;
		matrix T(k+1, vector<ll>(k+1,0));
		for(int i=1;i<k;i++)
		{
			T[i][i+1]=1;
		}
		for(int j=1;j<=k;j++)
		{
			T[k][j]=c[k-j+1];
		}
    /*for(int i=1;i<=k;i++)
    {
      for(int j=1;j<=k;j++)
      {
        cout<<T[i][j]<<" ";
      }
      cout<<endl;
    }
    cout<<endl;*/
		if(n<=k)
		{
			cout<< F[n]%MM;
      cout<<endl;
      continue;
		}
		T=power(T,n-1);
		ll ans=0;
		for(int i=1;i<=k;i++)
		{
			ans=(ans+T[1][i]*F[i])%MM;
		}
		cout<<ans<<endl;
	}
return 0;
}
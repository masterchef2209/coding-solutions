#include<bits/stdc++.h>
using namespace std;
#define int long long
#define MOD 1000000007

int bpow(int x, unsigned int y) 
{ 
    int res = 1LL;
   
    while (y > (int)0) 
    { 
        if (y & 1LL) 
            res = (res*x)%MOD; 
    
        y = y>>1LL; 
        x = (x*x)%MOD;
    } 
    return res%MOD; 
}

int modInverse(int a, int m) 
{ 
    int g = __gcd(a, m); 
    if (g != 1LL) 
    {
        cout << "Inverse doesn't exist"; 
        return -1;
    }
        
    else
    { 
        return bpow(a, m-2); 
    } 
} 

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--)
	{
		int n,k,m;
		cin>>n>>k>>m;
		if(m%2==0)
		{
			int m1=m/2;
			int p=((bpow(n,m1)*(n+k))%MOD+(bpow((n-1),m1)*(1-n-k))%MOD +MOD+MOD)%MOD;
			int q1=(bpow(n,m1)*(n+k))%MOD;
			int q=modInverse(q1,MOD);
			cout<<(p*q)%MOD<<endl;
		}
		else
		{
			int m1=m/2+1;
			int p=(bpow(n,m1)-bpow(n-1,m1)+MOD+MOD)%MOD;
			int q1=bpow(n,m1);
			int q=modInverse(q1,MOD);
			cout<<(p*q)%MOD<<endl;
		}
	}
return 0;
}
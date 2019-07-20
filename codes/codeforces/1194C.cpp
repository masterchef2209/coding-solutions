		/*Read the problem carefully before starting to work on it*/
#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
//#include <ext/pb_ds/assoc_container.hpp> 
//#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
//using namespace __gnu_pbds;

typedef long long ll;

//ll ncr(ll n,ll r){ll ans=1;r=min(r,n-r);for (int i=1;i<=r;i++){ans*=(n-r+i);ans/=i;}return ans;}

#define pb push_back
#define eb emplace_back
#define mp(x,y) make_pair(x,y)
#define mod 1000000007

double PI=3.1415926535897932384626;

//template<typename T> T power(T x,T y,ll m=mod){T ans=1;while(y>0){if(y&1LL) ans=(ans*x)%m;y>>=1LL;x=(x*x)%m;}return ans%m;}

//typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ost;

#define fi first
#define se second

bool check(string &str1, string &str2) 
{ 
	int m=str1.size();
	int n=str2.size();
   int j = 0; // For index of str1 (or subsequence 
  
   // Traverse str2 and str1, and compare current character  
   // of str2 with first unmatched char of str1, if matched  
   // then move ahead in str1 
   for (int i=0; i<n&&j<m; i++) 
       if (str1[j] == str2[i]) 
         j++; 
  
   // If all characters of str1 were found in str2 
   return (j==m); 
} 

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll q;
	cin>>q;
	while(q--)
	{
		string s,t,p;
		cin>>s>>t>>p;
		if(check(s,t)) //O(n)
		{
			ll ch[26],ch1[26];
			for(ll i=0;i<26;i++)
			{
				ch[i]=0;
				ch1[i]=0;
			}
			for(ll i=0;i<t.size();i++)
			{
				ch[(t[i]-'a')]++;
			}
			for(ll i=0;i<s.size();i++)
			{
				ch[(s[i]-'a')]--;
			}
			for(ll i=0;i<p.size();i++)
			{
				ch1[(p[i]-'a')]++;
			}
			int flag=1;
			for(ll i=0;i<26;i++)
			{
				if(ch[i]>ch1[i])
				{
					flag=0;
					break;
				}
			}
			if(flag==0)
				cout<<"NO\n";
			else
				cout<<"YES\n";
		}
		else
		{
			cout<<"NO\n";
		}
	}
    return 0;
}
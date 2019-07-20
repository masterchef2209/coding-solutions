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

//system one is excel type
//system two is coordinate kind

string onetotwo(string &s)
{
	string ret("");
	ret+="R";
	string dig(""),let("");
	for(ll i=0;i<s.size();i++)
	{
		if(isdigit(s[i]))
			dig+=s[i];
		else
			let+=s[i];
	}
	ret+=dig;
	ret+="C";
	ll num=0;
	ll temp=1;
	for(ll i=let.size()-1;i>=0;i--)
	{
		num+=(temp*(let[i]-'A'+1));
		temp*=26;
	}
	string hehe=to_string(num);
	ret+=hehe;
return ret;
}

string twotoone(string &s)
{
	ll pos=0;
	string part2(""),dig(""),part1("");
	while(s[pos]!='C')
	{
		if(pos>0)
		{
			part2+=s[pos];
		}
		pos++;
	}
	pos++;
	while(pos<s.size())
	{
		dig+=s[pos];
		pos++;
	}
	ll num=stoll(dig);
	//cout<<num<<endl;
	while(num>0)
	{
		ll rem=num%26;
		if(rem==0)
		    rem=26;
		num-=1;
		char lol=('A'+rem-1);
		part1=lol+part1;
		num/=26;
	}
	part1+=part2;
return part1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n;
	cin>>n;
	while(n--)
	{
		string s;
		cin>>s;
		ll c=0;
		for(ll i=1;i<s.size();i++)
		{
			if(isdigit(s[i]) && !isdigit(s[i-1]))
				c++;
		}
		if(c==1)
		{
			cout<<onetotwo(s)<<"\n";
		}
		else if(c==2)
		{
			cout<<twotoone(s)<<"\n";
		}
	}
    return 0;
}
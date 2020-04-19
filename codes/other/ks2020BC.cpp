		/*Read the problem carefully before starting to work on it*/
#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
//#include <ext/pb_ds/assoc_container.hpp> 
//#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
//using namespace __gnu_pbds;

typedef long long ll;

#define pb push_back
#define eb emplace_back
#define mp(x,y) make_pair(x,y)
#define mod 1000000000

double PI=3.1415926535897932384626;

//template<typename T> T power(T x,T y,ll m=mod){T ans=1;while(y>0){if(y&1LL) ans=(ans*x)%m;y>>=1LL;x=(x*x)%m;}return ans%m;}

//typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ost;

//mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
//#define rnd(x, y) uniform_int_distribution<ll>(x, y)(rng)

//struct custom_hash {
//    static uint64_t splitmix64(uint64_t x) {
//        // http://xorshift.di.unimi.it/splitmix64.c
//        x += 0x9e3779b97f4a7c15;
//        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
//        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
//        return x ^ (x >> 31);
//    }
//    size_t operator()(uint64_t x) const {
//        static const uint64_t FIXED_RANDOM = 
//            chrono::steady_clock::now().time_since_epoch().count();
//        return splitmix64(x + FIXED_RANDOM);
//    }
//};

#define fi first
#define se second

#define int long long

pair<ll,ll> getvalue(string s)
{
	ll delX=0;
	ll delY=0;
	ll fl=0;
	for(ll i=0;i<s.size();i++)
	{
		if(isdigit(s[i]))
		{
			fl=1;
			ll num=s[i]-'0';
			ll L=i+1;
			ll R=-1;
			ll stock=0;
			for(ll j=i+1;j<s.size();j++)
			{
				if(s[j]=='(')
				{
					stock++;
				}
				else if(s[j]==')')
				{
					stock--;
					if(stock==0)
					{
						R=j;
						break;
					}
				}
			}
			L++;
			R--;
			string s1=s.substr(L,R-L+1);
			auto pp=getvalue(s1);
			ll XX=(num * (pp.fi+mod)%mod )%mod;
			ll YY=(num * (pp.se+mod)%mod )%mod;
			delX=(delX + (XX+mod)%mod)%mod;
			delY=(delY + (YY+mod)%mod)%mod;
			i=R;
		}
		else if(s[i]=='N')
		{
			delY=(delY-1+mod)%mod;
		}
		else if(s[i]=='S')
		{
			delY=(delY+1+mod)%mod;
		}
		else if(s[i]=='E')
		{
			delX=(delX+1+mod)%mod;
		}
		else if(s[i]=='W')
		{
			delX=(delX-1+mod)%mod;
		}
	}
	return mp(delX,delY);
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll t;
    cin>>t;
    for(ll test=1;test<=t;test++)
    {
        cout<<"Case #"<<test<<": ";
        string s;
        cin>>s;
        auto pp=getvalue(s);
        pp.fi=(pp.fi+mod)%mod;
        pp.se=(pp.se+mod)%mod;
        cout<<pp.fi+1<<" "<<pp.se+1<<" ";
        cout<<"\n";
    }
    return 0;
}


//252908XL
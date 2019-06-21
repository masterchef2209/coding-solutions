		/*Read the problem carefully before starting to work on it*/
#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
//#include <ext/pb_ds/assoc_container.hpp> 
//#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
//using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;

//ll ncr(ll n,ll r){ll ans=1;r=min(r,n-r);for (int i=1;i<=r;i++){ans*=(n-r+i);ans/=i;}return ans;}

#define pb push_back
#define eb emplace_back
#define mp(x,y) make_pair(x,y)
#define mod 1000000007

double PI=3.1415926535897932384626;

//template<typename T> T power(T x,T y,ll m=mod){T ans=1;while(y>0){if(y&1LL) ans=(ans*x)%m;y>>=1LL;x=(x*x)%m;}return ans%m;}

#define bip(n) __builtin_popcount(n)//no of ones bit in binary!!
#define bictz(n) __builtin_ctz(n)//no of trailing zeroes in binary!!
#define biclz(n) __builtin_clz(n)//no of leading zeroes in binary!!
#define bffs(n) __builtin_ffs(n)//index of first one bit!!

typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;

typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ld> vd;
typedef vector<ll> vl;

//#define fi1 ifstream cin("input.txt")
//#define of1 ofstream cout("output.txt")
//typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ost;

#define fi first
#define se second

struct stanza
{
	string word1,word2;
};

vector<string> mm[100005][26];

vector<stanza>typeone,typetwo;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n;
	cin>>n;
	for(ll i=0;i<n;i++)
	{
		string tmp;
		cin>>tmp;
		ll vowelcount=0;
		char lastvowel;
		for(ll i=0;i<tmp.size();i++)
		{
			if((tmp[i]=='a')||(tmp[i]=='e')||(tmp[i]=='i')||(tmp[i]=='o')||(tmp[i]=='u'))
			{
				vowelcount++;
				lastvowel=tmp[i];
			}
		}
		mm[vowelcount][lastvowel-'a'].eb(tmp);
	}
	for(ll i=1;i<=n;i++)
	{
	    vector<string>bag;
	    for(ll j=0;j<26;j++)
	    {
	       if(!mm[i][j].empty())
	       {
	           while(mm[i][j].size()>1)
	           {
	               string x=mm[i][j].back();
	               mm[i][j].pop_back();
	               string y=mm[i][j].back();
	               mm[i][j].pop_back();
	               stanza st=(stanza){x,y};
	               typetwo.eb(st);
	           }
	           if(mm[i][j].size())
	            bag.eb(mm[i][j][0]);
	       }
	    }
	     while(bag.size()>1)
	           {
	               string x=bag.back();
	               bag.pop_back();
	               string y=bag.back();
	               bag.pop_back();
	               stanza st=(stanza){x,y};
	               typeone.eb(st);
	           }
	}
    while(typetwo.size()>typeone.size())
    {
        stanza lol=typetwo.back();
        typetwo.pop_back();
        typeone.push_back(lol);
    }
    cout<<typetwo.size()<<endl;
    for(ll i=0;i<typetwo.size();i++)
    {
        cout<<typeone[i].word1<<" "<<typetwo[i].word1<<endl;
        cout<<typeone[i].word2<<" "<<typetwo[i].word2<<endl;
    }
    return 0;
}
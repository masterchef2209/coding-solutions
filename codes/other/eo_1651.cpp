		/*Read the problem carefully before starting to work on it*/
#include <bits/stdc++.h>

//partially accepted

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

#define SSIZE 100005

ll n;

struct node
{
	bool leaf;
	node* child[2];
};

node* create()
{
	node *ret=new node();
	for(ll i=0;i<2;i++)	ret->child[i]=NULL;
	ret->leaf=false;
	return ret;
}

void add(node* root,string &s)
{
	for(ll i=0;i<s.size();i++)
	{
		if(root->child[s[i]-'0']==NULL)
		{
			root->child[s[i]-'0']=create();
		}
		root=root->child[s[i]-'0'];
	}
	root->leaf=true;
}

string getstringform(ll num)
{
	string s("");
	ll num1=num;
	while(num>0)
	{
		ll rem=num%2;
		s+=( (char)('0'+rem) );
		num>>=1;
	}
	ll noo=64-s.size();
	string cry(noo,'0');
	s+=cry;
	reverse(s.begin(),s.end());
	return s;
}

void addhelper(node* root,ll num)
{
	string s=getstringform(num);
	add(root,s);
}

ll search(node *root,string x)
{
    ll ans=0;
	for(ll i=0;i<x.size();i++)
	{
		ll ch=x[i]-'0';
		if(root->child[ch^1]==NULL)
		{
		    if(ch==1)
		    {
		        ans+=(1LL<<(63-i));
		    }
			root=root->child[ch];
		}
		else
		{
		    if((ch^1)==1)
		    {
		        ans+=(1LL<<(63-i));
		    }
			root=root->child[ch^1];
		}
	}
    return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	ll q;
	cin>>q;
	node* root=create();
	for(ll i=0;i<n;i++)
	{
		ll num;
		cin>>num;
		addhelper(root,num);
	}
	while(q--)
	{
		ll x;
		cin>>x;
		string x1=getstringform(x);
		cout<<search(root,x1)<<"\n";
	}
    return 0;
}


//252908XL
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

#define BSIZE 32

ll q;
map<ll,ll>mm;

struct node
{
	bool leaf;
	node *child[2];
};

node* create()
{
	node* ret=new node();
	ret->child[0]=NULL;
	ret->child[1]=NULL;
	return ret;
}

void add(node* root,ll num)
{
	for(ll i=BSIZE-1;i>=0;i--)
	{
		ll nn=(num>>i)&1;
		if(root->child[nn]==NULL)
			root->child[nn]=create();
		root=root->child[nn];
	}
	root->leaf=true;
}

ll query(node* root,ll num)
{
	ll ret=0;
	for(ll i=BSIZE-1;i>=0;i--)
	{
		ll nn=(num>>i)&1;
		if(root->child[nn^1]!=NULL)
		{
			ret+=( (1LL<<i) );
			root=root->child[nn^1];
		}
		else
		{
			root=root->child[nn];
		}
	}
	return ret;
}

node* remov(node* root,ll num,ll pos)
{
	if(root==NULL)
		return NULL;
	if(pos==-1)
	{
		root->leaf=false;
		if(root->child[0]==NULL && root->child[1]==NULL)
		{
			delete(root);
			root=NULL;
		}
		return root;
	}
	ll nn=(num>>pos)&1;
	root->child[nn]=remov(root->child[nn],num,pos-1);
	if(root->leaf==false && root->child[0]==NULL && root->child[1]==NULL)
	{
		delete(root);
		root=NULL;
	}
	return root;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>q;
	node* root=create();
	add(root,0);
	while(q--)
	{
		char ch;
		cin>>ch;
		ll num;
		cin>>num;
		if(ch=='+')
		{
			//add
			mm[num]++;
			add(root,num);
		}
		else if(ch=='?')
		{
			//query
			cout<<query(root,num)<<"\n";
		}
		else
		{
			//remove
			mm[num]--;
			if(mm[num]==0)
			{
				remov(root,num,BSIZE-1);
			}
		}
	}
    return 0;
}


//252908XL
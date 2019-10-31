		/*Read the problem carefully before starting to work on it*/

//not accepted

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

struct SegmentTreeNode {
  // Caution:
  // Segment tree is zero indexed and store initial values from 0 to (size-1)
  // array size of segment tree must be atleast (2*size)
  // syntax : SegmentTree<T-for values,T-for size> st(arr,size)  st.getValue(pos1,pos2)  st.update(pos,value)

  // variables to store aggregate statistics and
  // any other information required to merge these
  // aggregate statistics to form parent nodes
    

    ll val=0;
  void assignLeaf(ll value) {
    // T is the type of input array element
    // Given the value of an input array element,
    // build aggregate statistics for this leaf node
    val=value;
  }
  
  void merge(SegmentTreeNode& left, SegmentTreeNode& right) {
    // merge the aggregate statistics of left and right
    // children to form the aggregate statistics of
    // their parent node
    value=max(left.val,right.val);
  }
  
  // make sure return value of following function is correct
  ll getValue() {
    // V is the type of the required aggregate statistic
    // return the value of required aggregate statistic
    // associated with this node
    return val;
  }
};



// T is the type of input array elements
// V is the type of required aggregate statistic
template<class T, class V>
class SegmentTree {
  SegmentTreeNode* nodes;
  int N;

public:
  SegmentTree(T arr[], int N) {
    this->N = N;
    nodes = new SegmentTreeNode[getSegmentTreeSize(N)];
    buildTree(arr, 1, 0, N-1);
  }
  
  ~SegmentTree() {
    delete[] nodes;
  }
  
  V getValue(int lo, int hi) {
    SegmentTreeNode result = getValue(1, 0, N-1, lo, hi);
    return result.getValue();
  }
  
  void update(int index, T value) {
    update(1, 0, N-1, index, value);
  }
  
  private:	
  void buildTree(T arr[], int stIndex, int lo, int hi) {
    if (lo == hi) {
      nodes[stIndex].assignLeaf(arr[lo]);
      return;
    }
    
    int left = 2 * stIndex, right = left + 1, mid = (lo + hi) / 2;
    buildTree(arr, left, lo, mid);
    buildTree(arr, right, mid + 1, hi);
    nodes[stIndex].merge(nodes[left], nodes[right]);
  }
  
  SegmentTreeNode getValue(int stIndex, int left, int right, int lo, int hi) {
    if (left == lo && right == hi)
      return nodes[stIndex];
    	
    int mid = (left + right) / 2;
    if (lo > mid)
      return getValue(2*stIndex+1, mid+1, right, lo, hi);
    if (hi <= mid)
      return getValue(2*stIndex, left, mid, lo, hi);
    	
    SegmentTreeNode leftResult = getValue(2*stIndex, left, mid, lo, mid);
    SegmentTreeNode rightResult = getValue(2*stIndex+1, mid+1, right, mid+1, hi);
    SegmentTreeNode result;
    result.merge(leftResult, rightResult);
    return result;
  }
  
  int getSegmentTreeSize(int N) {
    int size = 1;
    for (; size < N; size <<= 1);
    return size << 1;
  }
  
  void update(int stIndex, int lo, int hi, int index, T value) {
    if (lo == hi) {
    nodes[stIndex].assignLeaf(value);
    return;
    }
    
    int left = 2 * stIndex, right = left + 1, mid = (lo + hi) / 2;
    if (index <= mid)
      update(left, lo, mid, index, value);
    else
      update(right, mid+1, hi, index, value);
    
    nodes[stIndex].merge(nodes[left], nodes[right]);
  }
};


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n;
	cin>>n;
	vector<ll>arr(2*n+5,0);
	ll segseg[500005];
	vector<ll>arr1(2*n+5,INT_MAX);
	priority_queue< pair<ll,ll> > >pq;
	for(ll i=0;i<n;i++)
	{
		cin>>arr[i];
		pq.push(mp(arr[i],i));
		arr[i+n]=arr[i];
		segseg=arr[i];
	}
	SegmentTree<ll,ll> st(segseg,2*n);
	arr1[0]=arr[0];
	for(ll i=1;i<(2*n);i++)
	{
		arr1[i]=min(arr[i],arr1[i-11]);
	}
	vector<ll>ans(n+5,0);
	while(!pq.empty())
	{
		pair<ll,ll> pp=pq.top();
		ll lo=pp.se+1;
		ll hi=2*n-1;
		while(lo<hi)
		{
			ll mid=lo+(hi-lo)/2;
			if( arr1[mid] < (pp.fi+1)/2 )
			{
				hi=mid;
			}
			else
			{
				lo=mid+1;
			}
		}
		ll temans;
		if(lo==(2*n-1) && arr1[lo] >= (pp.fi+1)/2)
		{
			temans=-1;
		}
		else
		{
			temans=abs(pp.se-lo);
		}
		ll hehe=st.getValue(pp.se,lo);
		if(hehe>pp.fi)
		{
			ans[pp.fi]=ans.hehe;
		}
		else
		{
			ans[pp.fi]=temans;
		}
	}
	for(ll i=0;i<n;i++)
	{
		cout<<ans[i]<<" ";
	}
    return 0;
}


//252908XL
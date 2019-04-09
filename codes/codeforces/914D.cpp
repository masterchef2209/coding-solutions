#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
//#include <ext/pb_ds/assoc_container.hpp> 
//#include <ext/pb_ds/tree_policy.hpp>
//ll ncr(ll n,ll r){ll ans=1;r=min(r,n-r);for (int i=1;i<=r;i++){ans*=(n-r+i);ans/=i;}return ans;}
using namespace std;
//using namespace __gnu_pbds;
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
typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;

typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;

typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ld> vd;
typedef vector<ll> vl;

//#define fi1 ifstream fin("input.txt")
//#define of1 ofstream fout("output.txt")
//typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ost;

#define fi first
#define se second

struct SegmentTreeNode {

  // variables to store aggregate statistics and
  // any other information required to merge these
  // aggregate statistics to form parent nodes
  int val;
    
  void assignLeaf(int value) {
    // T is the type of input array element
    // Given the value of an input array element,
    // build aggregate statistics for this leaf node
    val=value;
  }
  
  void merge(SegmentTreeNode& left, SegmentTreeNode& right) {
    // merge the aggregate statistics of left and right
    // children to form the aggregate statistics of
    // their parent node
    val=__gcd(left.val,right.val);
  }
  
  int getValue() {
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

int n;
int arr[3000000];

#define check(l,r,x) (st.getValue(l,r)%x==0)

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	SegmentTree<int,int>st(arr,n);
	int q;
	scanf("%d",&q);
	while(q--)
	{
		int status;
		scanf("%d",&status);
		if(status==1)
		{
			int l,r;
      int x;
			scanf("%d %d %d",&l,&r,&x);
			if(check(l-1,r-1,x))
				printf("YES\n");
			else
			{
				int flag=0;
				int lo=l-1,hi=r-1;
				while(lo<hi)
				{
					int mid=lo+(hi-lo)/2;
					bool status1,status2;
					status1=check(lo,mid,x);
					status2=check(mid+1,hi,x);
					if(status1==false && status2==false)
					{
						flag=1;
						break;
					}
					else if(status1==false)
					{
						hi=mid;
					}
					else if(status2==false)
					{
						lo=mid+1;
					}
				}
				if(flag==1)
					printf("NO\n");
				else if(flag==0)
					printf("YES\n");
			}
		}
		else if(status==2)
		{
			int pos;
      int val;
			scanf("%d %d",&pos,&val);
			st.update(pos-1,val);
		}
	}
    return 0;
}
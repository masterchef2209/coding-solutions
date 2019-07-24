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
#define int long long

int arr[1000005];

int getSum(int BITree[], int index) 
{ 
    int sum = 0; // Initialize result 
  
    // Traverse ancestors of BITree[index] 
    while (index > 0) 
    { 
        // Add current element of BITree to sum 
        sum += BITree[index]; 
  
        // Move index to parent node in getSum View 
        index -= index & (-index); 
    } 
    return sum; 
} 
  
// Updates a node in Binary Index Tree (BITree) at given index 
// in BITree.  The given value 'val' is added to BITree[i] and 
// all of its ancestors in tree. 
void updateBIT(int BITree[], int n, int index, int val) 
{ 
    // Traverse all ancestors and add 'val' 
    while (index <= n) 
    { 
       // Add 'val' to current node of BI Tree 
       BITree[index] += val; 
  
       // Update index to that of parent in update View 
       index += index & (-index); 
    } 
} 
  
// Returns inversion count arr[0..n-1] 
int getInvCount(int n) 
{ 
    int invcount = 0; // Initialize result 
  
    // Find maximum element in arr[] 
    int maxElement = 0; 
    for (int i=0; i<n; i++) 
        if (maxElement < arr[i]) 
            maxElement = arr[i]; 
  
    // Create a BIT with size equal to maxElement+1 (Extra 
    // one is used so that elements can be directly be 
    // used as index) 
    int BIT[maxElement+1]; 
    for (int i=1; i<=maxElement; i++) 
        BIT[i] = 0; 
  
    // Traverse all elements from right. 
    for (int i=n-1; i>=0; i--) 
    { 
        // Get count of elements smaller than arr[i] 
        invcount += getSum(BIT, arr[i]-1); 
  
        // Add current element to BIT 
        updateBIT(BIT, maxElement, arr[i], 1); 
    } 
  
    return invcount; 
} 

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n;
	cin>>n;
	for(ll i=0;i<n;i++)
	    cin>>arr[i];
	int pp=getInvCount(n)%2;
	int pp1=n%2;
	if(pp==pp1)
	    cout<<"Petr\n";
	else
	    cout<<"Um_nik\n";
    return 0;
}


//252908XL
#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision; 
using namespace std;
#define pb push_back
#define eb emplace_back
#define mp(x,y) make_pair(x,y)
#define mod 1000000007
double PI=3.1415926535897932384626;
#define int long long
typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;
#define int long long
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;

typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ld> vd;
typedef vector<ll> vl;

#define f first
#define s second

vector< multiset<int> >A(1100);
vector< multiset<int> >B(1100);

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            int temp;
            cin>>temp;
            A[i+j].insert(temp);
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            int temp;
            cin>>temp;
            B[i+j].insert(temp);
        }
    }
    for(int i=0;i<n+m-1;i++)
    {
        if(A[i]!=B[i])
        {
            cout<<"NO"<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;
    return 0;
}
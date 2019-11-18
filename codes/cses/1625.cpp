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

string s;
int grid[7][7];

int dr[4]={0,1,0,-1};
int dc[4]={1,0,-1,0};

ll f(ll x,ll y,ll moves,char ch)
{
    if(moves==48)
    {
        if(x==6 && y==0)
            return 1;
        return 0;
    }
    //heuristics
    // 1) reaching early at destination
    if(x==6 && y==0)
        return 0;
    // 2) if grid is divided into 2 unvisited parts due to dual choice
    if(ch=='L' && x>0 && x<6 && (y==0 || grid[x][y-1]) && !grid[x+1][y] && !grid[x-1][y])
        return 0;
    if(ch=='R' && x>0 && x<6 && (y==6 || grid[x][y+1]) && !grid[x+1][y] && !grid[x-1][y])
        return 0;
    if(ch=='U' && y>0 && y<6 && (x==0 || grid[x-1][y]) && !grid[x][y+1] && !grid[x][y-1])
        return 0;
    if(ch=='D' && y>0 && y<6 && (x==6 || grid[x+1][y]) && !grid[x][y+1] && !grid[x][y-1])
        return 0;
        
    if(s[moves]=='?')
    {
        ll ret=0;
        for(ll k=0;k<4;k++)
        {
            ll xx=x+dr[k];
            ll yy=y+dc[k];
            if(xx<0 || xx>6 || yy<0 || yy>6)
                continue;
            if(grid[xx][yy])
                continue;
            grid[xx][yy]=true;
            ret+=f(xx,yy,moves+1,"RDLU"[k]);
            grid[xx][yy]=false;
        }
        return ret;
    }
    if(s[moves]=='L')
        y--;
    else if(s[moves]=='R')
        y++;
    else if(s[moves]=='U')
        x--;
    else if(s[moves]=='D')
        x++;
    if(x<0 || x>6 || y<0 || y>6)
        return 0;
    if(grid[x][y])
        return 0;
    ll ret=0;
    grid[x][y]=true;
    ret+=f(x,y,moves+1,s[moves]);
    grid[x][y]=false;
    return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>s;
	grid[0][0]=true;
	cout<<f(0,0,0,0)<<"\n";
	grid[0][0]=false;
    return 0;
}


//252908XL
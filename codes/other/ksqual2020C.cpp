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
#define mod 1000000007

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

struct Interval{
    pair<int,int> interval;
    int index;
};
 
bool comp(const Interval &i1 , const Interval &i2){
    if(i1.interval.first < i2.interval.first)
        return true;
    if(i1.interval.first == i2.interval.first && i1.interval.second <= i2.interval.second)
        return true;
    return false;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    for(ll test=1;test<=t;test++)
    {
        int N;
        cin>>N;
        vector<Interval> input(N);
        for(int i = 0 ; i < N ; i++){
            cin>>input[i].interval.first>>input[i].interval.second;
            input[i].index = i;
        }
        sort(input.begin() , input.end() , comp);
 
        vector<Interval> g1;
        vector<Interval> g2;
 
        bool possible = true;
 
        for(auto it : input){
 
            if(g1.empty()){
                g1.push_back(it);
                continue;
            }
            if(it.interval.first >= g1.back().interval.second){
                g1.push_back(it);
                continue;
            }
            if(g2.empty()){
                g2.push_back(it);
                continue;
            }
            if(it.interval.first >= g2.back().interval.second){
                g2.push_back(it);
                continue;
            }
            possible = false;
            break;
 
        }
        if(!possible){
            printf("Case #%d: %s\n" , Case , "IMPOSSIBLE");
            continue;
        }
        char ans[N+1] = {};
        for(auto it : g1)
            ans[it.index] = 'C';
        for(auto it : g2)
            ans[it.index] = 'J';
        ans[N] = '\0';
 
        printf("Case #%d: %s\n" , Case , ans);
    }
    return 0;
}


//252908XL
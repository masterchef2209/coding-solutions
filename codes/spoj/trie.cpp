/*
Given a grid of characters of size n*m and q words in a dictionary.
Print the words that lie in the grid. (Diagonal movement allowed)

Data Structure Used - Trie
Time Complexity - O(n*m*k) where k is the length of the longest word in the dictionary

Author - hiteshpardasani99
*/

#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define pll pair<ll,ll>
using namespace std;

struct node
{
    bool leaf;  //if the node is a leaf then, a word in the dictionary ends at this node.
    node* child[26];
};

node* create()
{
    node* ret = new node();
    for(int i=0;i<26;i++)ret->child[i]=NULL;
    ret->leaf=false;
    return ret;
}

ll n,m,q;
char grid[1001][1001];  //input grid
int vis[1001][1001];    //visit array for dfs
string dict[100005];    //Dictionary
vector<char> ans;
set<vector<char>> s;    //Set to store the answer
pll dir[8]={{-1,-1},{-1,0},{-1,1},{0,1},{0,-1},{1,1},{1,0},{1,-1}};

node* root=create();

void add(string x)
{
    node* ex=root;  // to keep a copy of root
    for(int i=0;i<x.length();i++)
    {
        if(root->child[x[i]-'a']==NULL)
        {
            root->child[x[i]-'a']=create();
        }
        root=root->child[x[i]-'a'];
    }
    root->leaf=true;
    root=ex;
}

bool check(pll ne)
{
    return (ne.ff>=0&&ne.ss>=0&&ne.ff<n&&ne.ss<m);
}

void dfs(pll c)
{
    if(root->child[grid[c.ff][c.ss]-'a']!=NULL) //if the current char is present in trie
    {
        node *ex=root;
        root = root->child[grid[c.ff][c.ss]-'a'];
        ans.pb(grid[c.ff][c.ss]);
        vis[c.ff][c.ss]=1;
        for(int i=0;i<8;i++)        //to check in all the directions
        {
            pll ne={c.ff+dir[i].ff,c.ss+dir[i].ss};
            if(check(ne)&&!vis[ne.ff][ne.ss])
            {
                dfs(ne);
            }
        }
        root=ex;
        ans.pop_back();
        vis[c.ff][c.ss]=0;
    }
    else
    {
        if(root->leaf && ans.size())
        {
            s.insert(ans);
        }
    }
}

void solve()
{
    node* ex=root;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            pll curr={i,j};
            root = ex;
            dfs(curr);  //check from every possible starting point
        }
    }
    for(auto it=s.begin();it!=s.end();it++)
    {
        vector<char> v=*it;
        for(int i=0;i<v.size();i++)cout<<v[i];cout<<endl;
    }
}


int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)cin>>grid[i][j];
    }
    cin>>q;
    for(int i=0;i<q;i++)
    {
        cin>>dict[i];
        add(dict[i]);
    }
    solve();
    return 0;
}

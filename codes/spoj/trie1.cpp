#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
char ch[22];
struct trie
{
    int ct;
    int fin;
    struct trie *sons[27];
};
struct trie *root;
struct trie *newnode()
{
    struct trie *x;
    x=(struct trie*)malloc(sizeof(struct trie));
    x->ct=0;
    x->fin=0;
    for(int i=0;i<27;i++) x->sons[i]=NULL;
    return x;
};
void add_to_trie()
{
    struct trie *node=root;
    int mar=strlen(ch);
    for(int i=0;i<mar;i++)
    {
        if(node->sons[ch[i]-'a']==NULL) node->sons[ch[i]-'a']=newnode();
        node=node->sons[ch[i]-'a'];
        ++node->ct;
    }
    ++node->fin;
}
void rem_from_trie()
{
    struct trie *node=root;
    struct trie *node2;
    int mar=strlen(ch);
    for(int i=0;i<mar;i++)
    {
        node2=node->sons[ch[i]-'a'];
        --node2->ct;
        if(node2->ct==0) node->sons[ch[i]-'a']=NULL;
        if(node->ct==0) free(node);
        node=node2;
    }
    --node2->fin;
}
int ap_in_trie()
{
    struct trie *node=root;
    int mar=strlen(ch);
    for(int i=0;i<mar;i++)
    {
        if(node->sons[ch[i]-'a']==NULL) return 0;
        node=node->sons[ch[i]-'a'];
    }
    return node->fin;
}
int prefix_in_trie()
{
    struct trie *node=root;
    int mar=strlen(ch);
    int pt=0;
    for(int i=0;i<mar;i++)
    {
        if(node->sons[ch[i]-'a']==NULL) return pt;
        ++pt;
        node=node->sons[ch[i]-'a'];
    }
    return pt;
}
inline void citire()
{
    root=newnode();
    root->ct=11;
    while(1)
    {
        int tip;
        scanf("%d%s",&tip,ch);
        if(feof(stdin)) break;
        if(tip==0) add_to_trie();
        else if(tip==1) rem_from_trie();
        else if(tip==2) printf("%d\n",ap_in_trie());
        else if(tip==3) printf("%d\n",prefix_in_trie());
    }
}
int main()
{
    freopen ("trie.in","r",stdin);
    freopen ("trie.out","w",stdout);
    citire();
}
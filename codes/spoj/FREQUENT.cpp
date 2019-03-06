#include<bits/stdc++.h>
using namespace std;

#define int long long


struct SegmentTreeNode {

  int maxfreq,leftvlu,rightvlu,leftfreq,rightfreq;
  // variables to store aggregate statistics and
  // any other information required to merge these
  // aggregate statistics to form parent nodes
    
  void assignLeaf(int value) {
    // T is the type of input array element
    // Given the value of an input array element,
    // build aggregate statistics for this leaf node
    rightfreq=leftfreq=maxfreq=1;
    leftvlu=rightvlu=value;
  }
  
  void merge(SegmentTreeNode& left, SegmentTreeNode& right) {
    // merge the aggregate statistics of left and right
    // children to form the aggregate statistics of
    // their parent node
    leftvlu=left.leftvlu;
    rightvlu=right.rightvlu;
    if(left.leftvlu==right.leftvlu)
    {
      leftfreq=left.leftfreq+right.leftfreq;
    }
    else
    {
      leftfreq=left.leftfreq;
    }
    if(left.rightvlu==right.rightvlu)
    {
      rightfreq=left.rightfreq+right.rightfreq;
    }
    else
    {
      rightfreq=right.rightfreq;
    }
    if(left.rightvlu!=right.leftvlu)
    {
      maxfreq=max(left.maxfreq,right.maxfreq);
    }
    else
    {
      maxfreq=max({left.maxfreq,right.maxfreq,left.rightfreq+right.leftfreq});
    }
  }
  
  int getValue() {
    // V is the type of the required aggregate statistic
    // return the value of required aggregate statistic
    // associated with this node
    return maxfreq;
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



signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n,q;
  int arr[500005];
  while(cin>>n)
  {
    if(n==0)
      break;
    cin>>q;
    for(int i=0;i<n;i++)
    {
      cin>>arr[i];
    }
    SegmentTree<int,int> st(arr,n);
    for(int u=0;u<q;u++)
    {
      int a,b;
      cin>>a>>b;
      cout<< st.getValue(a-1,b-1) <<endl;
    }
  }
  
return 0;
}
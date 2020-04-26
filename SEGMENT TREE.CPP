#include<bits/stdc++.h>
#define ll  long long int
#define ull unsigned long long 
#define ff first
#define ss second
#define fast ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pb push_back 
#define mp make_pair
#define inf 2000000009
#define mod 1000000007
#define ld long double
using namespace std;
vector<ll> tree,a;

void segtree_build(ll node,ll start, ll end)
{
  if(start==end)
    tree[node]=a[start];
  else
  {
    ll mid=(start+end)/2;

    segtree_build(node*2+1,start,mid);
    segtree_build(node*2+2,mid+1,end);
    tree[node]=tree[node*2+1]+tree[node*2+2];
  }
}

ll segtree_query(ll node,ll start,ll end,ll l ,ll r)
{
  if(start>r or end<l) return 0;
    if(start>=l and end<=r) return tree[node];
  
    ll mid=(start+end)/2;
    return segtree_query(node*2+1,start,mid,l,r) + segtree_query(node*2+2,mid+1,end,l,r);
}


void segtree_update(ll node,ll start,ll end,ll index,ll val)
{
  if(start==end)
    a[index]+=val,tree[node]+=val;
  else
  {
    ll mid=(start+end)/2;

    if(mid>=index)
    segtree_update(node*2+1,start,mid,index,val);
      else
    segtree_update(node*2+2,mid+1,end,index,val);

    tree[node]=tree[node*2+1]+tree[node*2+2];
  }
}

int main()
{ 
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

fast;

ll n;
cin>>n;
tree.assign(4*n,0);
a.assign(n,0);

for(ll i=0;i<n;i++)
cin>>a[i];

segtree_build(0,0,n-1);

cout<<segtree_query(0,0,n-1,0,3)<<endl;

segtree_update(0,0,n-1,1,3);

cout<<segtree_query(0,0,n-1,0,3)<<endl;

}

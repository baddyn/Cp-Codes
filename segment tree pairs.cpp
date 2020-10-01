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
vector<ll> a;
vector<pair<ll,ll> > tree;

pair<ll,ll> combine(pair<ll,ll>p1,pair<ll,ll>p2 )
{
    if(p1.ff==p2.ff)
        return {p1.ff,p1.ss+p2.ss};
    if(p1.ff>p2.ff) return p1;
    return p2;
}

void segtreepairbuild(ll node,ll start,ll end)
{
    if(start==end)
        tree[node]={a[start],(ll)1};
    else
    {
        ll mid=(start+end)/2;
        segtreepairbuild(node*2+1,start,mid);
        segtreepairbuild(node*2+2,mid+1,end);
        tree[node]=combine(tree[node*2+1],tree[node*2+2]);
    }
}

pair<ll,ll> segtreepairquery(ll node,ll start,ll end,ll l,ll r)
{
    if(start>r or end<l) return{-inf,0};
    if(start>=l and end<=r) return tree[node];

    ll mid=(start+end)/2;

    return combine(segtreepairquery(node*2+1,start,mid,l,r),segtreepairquery(node*2+2,mid+1,end,l,r));
}

void segtreepairupdate(ll node,ll start,ll end,ll index,ll val)
{
    if(start==end)
        tree[node].ff+=val,a[index]+=val;
    else
    {
        ll mid=(start+end)/2;

        if(mid>=index)
        segtreepairupdate(node*2+1,start,mid,index,val);
        else
        segtreepairupdate(node*2+2,mid+1,end,index,val);
    tree[node]=combine(tree[node*2+1],tree[node*2+2]);
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
/*
5
1
8
1
8
-7
*/

tree.assign(4*n,{0,0});
a.assign(n,0);

for(ll i=0;i<n;i++)
cin>>a[i];

segtreepairbuild(0,0,n-1);

pair<ll,ll> ret=segtreepairquery(0,0,n-1,0,3);
cout<<ret.ff<<" "<<ret.ss<<endl;

segtreepairupdate(0,0,n-1,2,7);

ret=segtreepairquery(0,0,n-1,0,3);
cout<<ret.ff<<" "<<ret.ss<<endl;
}
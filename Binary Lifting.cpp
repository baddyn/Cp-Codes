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
ll n,l,timer;
vector<ll> adj[2000009];
vector<vector<ll> > up;
vector<ll> tin,tout;

void dfs(ll node,ll par)
{
    tin[node]=++timer;
    up[node][0]=par;

    for(ll i=1;i<=l;i++)
        up[node][i]=up[up[node][i-1]][i-1];

    for(ll j:adj[node])
        if(j!=par)
            dfs(j,node);

    tout[node]=++timer;
}

void build(ll root)
{
    tin.resize(n),tout.resize(n);
    timer=0;
    l=ceil(log2(n));
    up.assign(n,vector<ll>(l+1));
    dfs(root,root);
}

bool ancestor(ll u,ll v)
{
    return tin[u]<=tin[v] and tout[u]>=tout[v];
}

ll lca(ll u,ll v)
{
    if(ancestor(u,v))
        return u;
    if(ancestor(v,u))
        return v;

    for(ll i=l;i>=0;i--)
        if(!ancestor(up[u][i],v))
            u=up[u][i];

        return up[u][0];
}
int main()
{ 
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

fast;
cin>>n;

for(ll i=0;i<n-1;i++)
{
    ll x,y;
    cin>>x>>y;
    adj[x-1].pb(y-1);
    adj[y-1].pb(x-1);
}

build(0);

//cout<<lca(5-1,6-1)<<endl<<lca(1-1,7-1)<<endl<<lca(2-1,5-1)<<endl<<lca(9-1,8-1)<<endl;



}

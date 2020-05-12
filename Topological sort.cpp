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
ll n,m;
vector<ll> adj[2000009];
vector<bool> vis;
 vector<ll> ans;

void dfs(ll v)
{
  vis[v]=1;

  for(ll j:adj[v])
    if(!vis[j])
      dfs(j);

    ans.pb(v+1);
}

void top_sort()
{
  vis.assign(n,0);

  for(ll i=0;i<n;i++)
    if(!vis[i])
      dfs(i);

    reverse(ans.begin(),ans.end());

    for(auto i:ans)
      cout<<i<<" ";
    cout<<endl;

}
int main()
{ 
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

fast;
cin>>n>>m;

for(ll i=0;i<m;i++)
{
  ll x,y;
  cin>>x>>y;
  adj[x-1].pb(y-1);
}

top_sort();

}

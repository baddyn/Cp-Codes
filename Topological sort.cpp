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

void dfs(ll v,vector<ll>& ans,vector<bool>& vis)
{
  vis[v]=1;

  for(ll j:adj[v])
    if(!vis[j])
      dfs(j,ans,vis);

    ans.pb(v);
}

void top_sort()
{
  vector<bool> vis(n,0);
  vector<ll> ans;

  for(ll i=0;i<n;i++)
    if(!vis[i])
      dfs(i,ans,vis);

    reverse(ans.begin(),ans.end());

    for(auto i:ans)
      cout<<i+1<<" ";
    cout<<endl;

}

void kahn()
{
  vector<ll> ideg(n,0);
  vector<ll> ans;

  for(ll i=0;i<n;i++)
    for(ll j:adj[i])
      ideg[j]++;

  queue<ll> q;
  for(ll i=0;i<n;i++)
    if(ideg[i]==0)
      q.push(i);

    while(!q.empty())
    {
      ll v=q.front();
      q.pop();
      ans.pb(v);

      for(auto j:adj[v])
        {
          ideg[j]--;
          if(ideg[j]==0)
            q.push(j);
        }
    }

    for(auto i:ans)
      cout<<i+1<<" ";

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
kahn();

}

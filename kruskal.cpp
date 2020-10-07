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
vector<ll> parent;
vector<ll> rnk;

/*
6
9
5 4 9
5 1 4
4 3 5
4 2 3
4 1 1
1 2 2
3 2 3
3 6 8
2 6 7
*/


struct edge
{
  ll u,v,wt;
};

bool fun(edge &e1,edge &e2)
{
  return e1.wt<e2.wt;
}

vector<edge> alledges;



ll kruskal()  // mlogm +n*n algorithm without union find
{
  sort(alledges.begin(),alledges.end(),fun);
  ll cost=0;

  vector<ll> treeid(n,0);
  vector<edge> ans;

  for(ll i=0;i<n;i++)
    treeid[i]=i;

  for(edge e:alledges)
  {
    if(treeid[e.u]!=treeid[e.v])
    {
      cost+=e.wt;
      ans.pb(e);
      ll oldid=treeid[e.u],newid=treeid[e.v];

      for(ll i=0;i<n;i++)
        if(treeid[i]==oldid)
          treeid[i]=newid;
    }
  }
  for(edge e:ans)
    cout<<e.u+1<<" "<<e.v+1<<" "<<e.wt<<endl;
  return cost;

}

void make_set(ll v)
{
  parent[v]=v;
  rnk[v]=0;
}

ll find_set(ll v)
{
  if(parent[v]==v)
    return v;
  return parent[v]=find_set(parent[v]);
}

void union_set(ll a,ll b)
{
  a=find_set(a);
  b=find_set(b);

  if(a!=b)
  {
    if(rnk[a]<rnk[b])
      swap(a,b);
    parent[b]=a;

    if(rnk[a]==rnk[b])
      rnk[a]++;
  }
}

ll kruskal_dsu()
{
  sort(alledges.begin(),alledges.end(),fun);
  ll cost=0;

  parent.assign(n,-1);
  rnk.assign(n,-1);

  vector<edge> ans;

  for(ll i=0;i<n;i++)
    make_set(i);

  for(edge e:alledges)
  {
    if(find_set(e.u)!=find_set(e.v))
    {
      cost+=e.wt;
      ans.pb(e);
      union_set(find_set(e.u),find_set(e.v));
    }
  }

  for(auto i:ans)
    cout<<i.u+1<<" "<<i.v+1<<" "<<i.wt<<endl;
  return cost;


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
  edge e;
  cin>>e.u>>e.v>>e.wt;
  e.u--,e.v--;
  alledges.pb(e);
}

    cout<<kruskal()<<endl;
cout<<kruskal_dsu()<<endl;

}

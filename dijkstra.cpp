#include<bits/stdc++.h>
#define ll  long long int
#define ull unsigned long long 
#define ff first
#define ss second
#define fast ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pb push_back 
#define mp make_pair
#define inf 100000000000000000
#define mod 1000000007
#define ld long double
#define pll pair<ll,ll>
using namespace std;
 
 
int main()
{ 
// 	#ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
 
 
fast;
 
ll n,m;
cin>>n>>m;
 
vector<pair<ll,ll> > adj[n];
 
for(ll i=0;i<m;i++)
{
	ll u,v,c;
	cin>>u>>v>>c;
	u--,v--;
 
	adj[u].pb({v,c});
	// adj[v].pb({u,c});
}
 
set<pair<ll,ll> > sett;
vector<ll> d;
d.assign(n,inf);
d[0]=0;
sett.insert({0,0});
 
while(!sett.empty())
{
	ll v=(sett.begin()->ss);
	sett.erase(sett.begin());
 
	for(auto j:adj[v])
	{
		ll to=j.ff,wt=j.ss;
 
		if(d[to]>d[v]+wt)
		{
			sett.erase({d[to],to});
			d[to]=d[v]+wt;
			sett.insert({d[to],to});
		}
	}
}
 
for(ll i=0;i<n;i++)
cout<<d[i]<<" ";
}

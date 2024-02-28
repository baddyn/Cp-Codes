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
 
ll n,m,q;
cin>>n>>m>>q;
 
vector<pair<ll,ll> > adj[n];
 
ll d[n][n];
 
for(ll i=0;i<n;i++)
	for(ll j=0;j<n;j++)
	{
		if(i!=j)
		d[i][j]=inf;
	else
		d[i][j]=0;
    }
 
 
for(ll i=0;i<m;i++)
{
	ll u,v,c;
	cin>>u>>v>>c;
	u--,v--;
 
	adj[u].pb({v,c});
	adj[v].pb({u,c});
	d[u][v]=min(d[u][v],c);
	d[v][u]=min(d[v][u],c);
}
 
 
	for(ll k=0;k<n;k++)
		for(ll i=0;i<n;i++)
			for(ll j=0;j<n;j++)
				if(d[i][k]<inf and d[k][j]<inf)
					d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
 
	while(q--)
	{
		ll a,b;
		cin>>a>>b;
		a--,b--;
		if(d[a][b]!=inf)
		cout<<d[a][b];
		else cout<<-1;
		cout<<'\n';
	}
 
 
}

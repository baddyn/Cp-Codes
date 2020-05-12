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
vector<ll> adj[20000];

bool bipartite_check()
{
	bool f=1;

	queue<ll> q;
	vector<ll> side(n,-1);

	for(ll i=0;i<n;i++)
	{
		if(side[i]==-1)
		{
			side[i]=0;
			q.push(i);

			while(!q.empty())
			{
				ll v=q.front();
				q.pop();

				for(auto u:adj[v])
				{
					if(side[u]==-1)
						side[u]=side[v]^1,q.push(u);
					else if(side[u]==side[v])
					{
						f=0;
						break;
					}
				}
			}
		}
	}
	return f;
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
	x--,y--;
	adj[x].pb(y);
	adj[y].pb(x);
}

cout<<bipartite_check();




}

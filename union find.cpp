#include<bits/stdc++.h>
#define ll  long long int
#define ull unsigned long long 
#define ff first
#define ss second
#define fast ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pb push_back 
#define mp make_pair
#define inf 1000000000000000
#define mod 1000000007
#define ld long double
#define pll pair<ll,ll>
using namespace std;

vector<ll> par,sz;

void make_set(ll v)
{
	par[v]=v;
	sz[v]=1;
}


ll find_set(ll v)
{
	if(v==par[v])
		return v;
	return par[v]=find_set(par[v]);
}


void union_set(ll u,ll v)
{
	u=find_set(u);
	v=find_set(v);

	if(u!=v)
	{
		if(sz[u]<sz[v])
			swap(u,v);
		par[v]=u;
		sz[u]+=sz[v];
	}


}


int main()
{ 
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

fast;

}

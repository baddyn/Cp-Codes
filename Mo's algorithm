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
ll block=555;
ll cnt=0;
vector<ll> a;

vector<ll> freq(2000009,0);
bool fun(pair<pair<ll,ll> ,ll> p1, pair<pair<ll,ll> ,ll> p2)
{
	if(p1.ff.ff/block!=p2.ff.ff/block)return p1.ff.ff<p2.ff.ff;
	return p1.ff.ss<p2.ff.ss;
}

void add(ll idx)
{
	freq[a[idx]]++;
	if(freq[a[idx]]==1)cnt++;
}

void remove(ll idx)
{
	freq[a[idx]]--;
	if(freq[a[idx]]==0)cnt--;
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

a.assign(n,0);
for(ll i=0;i<n;i++)cin>>a[i];

ll q;
cin>>q;

vector<pair<pair<ll,ll>,ll> > query(q);
for(ll i=0;i<q;i++)
cin>>query[i].ff.ff>>query[i].ff.ss,query[i].ss=i,query[i].ff.ff--,query[i].ff.ss--;

sort(query.begin(),query.end(),fun);

vector<ll> ans(q,0);

ll curl=0,curr=0;

for(ll i=0;i<q;i++)
{
	ll l=query[i].ff.ff,r=query[i].ff.ss;

	while(curl<l)
		remove(curl),curl++;
	while(curl>l)
		add(curl-1),curl--;
	while(curr<=r)
		add(curr),curr++;
	while(curr>r+1)
		remove(curr-1),curr--;

	ans[query[i].ss]=cnt;
}

for(ll i=0;i<q;i++)
	cout<<ans[i]<<endl;
}

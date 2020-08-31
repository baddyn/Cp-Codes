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

vector<ll> kmp(string s)
{
	ll n=s.size();

	vector<ll> pi(n,0);

	for(ll i=1;i<n;i++)
	{
		ll j=pi[i-1];
		while(j>0 and s[j]!=s[i])
			j=pi[j-1];

		if(s[i]==s[j])
			j++;

		pi[i]=j;
	}
	return pi;
}


int main()
{ 
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

fast;

string s;
cin>>s;

vector<ll> ans=kmp(s);
for(auto i:ans)
cout<<i<<" ";

}

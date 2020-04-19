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


void small_left(vector<ll>&v,vector<ll> &v1)
{
	v1[0]=inf;
	stack<ll> temp;
	temp.push(0);

	for(ll i=1;i<v.size();i++)
	{
		while(!temp.empty() )
		{
			ll idx=temp.top();
			if(v[idx]>v[i])
				temp.pop();
			else break;
		}

		if(temp.empty()) v1[i]=inf;
		else v1[i]=v[temp.top()];
		temp.push(i);
	}
}

void small_right(vector<ll>& v,vector<ll>&v1)
{
	reverse(v.begin(),v.end());
	small_left(v,v1);
	reverse(v.begin(),v.end());
	reverse(v1.begin(),v1.end());
}

void large_left(vector<ll>&v,vector<ll>&v1)
{
	for(ll i=0;i<v.size();i++)
		v[i]*=-1;
	small_left(v,v1);
	for(ll i=0;i<v.size();i++) v[i]*=-1,v1[i]*=-1;
}

void large_right(vector<ll>&v,vector<ll>&v1)
{
	for(ll i=0;i<v.size();i++)
		v[i]*=-1;
	small_right(v,v1);
	for(ll i=0;i<v.size();i++)
		v[i]*=-1,v1[i]*=-1;
}

int main()
{ 
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

fast;
vector<ll> v={1,6,4,10,2,5};
ll n=v.size();
vector<ll> v1(n,0),v2(n,0),v3(n,0),v4(n,0);

small_left(v,v1);

for(auto i:v1)
cout<<i<<" ";
small_right(v,v2);
cout<<endl;
for(auto i:v2)
cout<<i<<" ";
large_left(v,v3);
cout<<endl;
for(auto i:v3)
cout<<i<<" ";
large_right(v,v4);
cout<<endl;
for(auto i:v4)
cout<<i<<" ";

}

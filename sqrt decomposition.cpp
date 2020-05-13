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
ll blk=750;


int main()
{ 
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

fast;

ll n;
cin>>n;
//ll blk=ceil(sqrt(n));

/*
7
1 2 3 4 5 6 7

2
1 5
3 7*/

ll a[n];
vector<ll> b(n/blk+1,0);
for(ll i=0;i<n;i++)cin>>a[i],b[i/blk]+=a[i];

ll q;
cin>>q;

while(q--)
{
    ll l,r;
    cin>>l>>r;
    l--,r--;

    ll lb=l/blk,rb=r/blk;
    ll sum=0;

    if(lb==rb)
        for(ll i=l;i<=r;i++)
            sum+=a[i];

    else
    {
        for(ll i=l;i<(lb+1)*blk;i++)sum+=a[i];
        for(ll i=lb+1;i<rb;i++)sum+=b[i];
        for(ll i=rb*blk;i<=r;i++)sum+=a[i];
    }
cout<<sum<<endl;
}

}

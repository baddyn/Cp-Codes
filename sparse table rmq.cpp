/*    FAILING IS AN ART
       AND 
     I HAVE MASTERED IT
*/
#include<bits/stdc++.h>
#define ll long long int
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
vector<ll> logval(30);
ll st[1000000][30];

ll query(ll l ,ll r)
{
    ll window=logval[r-l+1];
       return min(st[l][window],st[r-(1<<window)+1][window]);
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

    ll a[n];
    for(ll i=0;i<n;i++)
        cin>>a[i];

    logval[1]=0;
    for(ll i=2;i<=n;i++)
        logval[i]=logval[i/2]+1;

    ll k=logval[n];
    k++;
    memset(st,0,sizeof(st));

    for(ll i=0;i<n;i++)
        st[i][0]=a[i];

for(ll j=1;j<=k;j++)
{
    for(ll i=0;i+(1<<j)<=n;i++)
        st[i][j]=min(st[i][j-1],st[i+(1<<(j-1))][j-1]);
}

    ll q;
    cin>>q;
while(q--)
{
   ll l,r;
   cin>>l>>r;
   cout<<query(l,r)<<endl;
}



}

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
//bit implemented on 1 indexing
//application INVERSION COUNT using coord compression
// need reversible function for working of bit

ll bit[200009]={0};
ll bit2[200009]={0};
vector<ll> bit3(200009,0);
vector<ll> bit4(200009,0);
ll a[200005];

ll n; 

void coord_compression(vector<ll> &v)
{
  ll sz=v.size();
  vector<pair<ll,ll> > temp;
  
  for(ll i=0;i<sz;i++)
    temp.pb(mp(v[i],i));

  sort(temp.begin(),temp.end());

  for(ll i=0;i<sz;i++)
    v[temp[i].ss]=i;
}

ll log_fun(ll n)
{
  ll i=0,j=1;
  while(1)
  {
    if(j*2<=n) i++,j*=2;
    else break;
  }
  return i;
}

void update(ll i,ll val)
{
  i++;

    for(i;i<=n ;i+=i&(-i))
       bit[i]+=val;
}

void build()
{
    for(ll i=0;i<n;i++)
   update(i,a[i]);  
}

// answers query if input like 0-5 sum
ll query(ll l)
{
    ll sum=0;
    l++;

 for(ll i=l;i>0;i-=i&(-i))
 sum+=bit[i];

   return sum; 
}

ll range_query(ll l,ll r)
{
    return query(r)-query(l-1);
}

// make sure if call height multiple times 
//store logn beforehand and dont do multiple computtns
ll bit_search_height(ll v)
{
  ll sum=0,cur=0;

  for(ll i=log_fun(n);i>=0;i--)
  {
    ll x=cur+(1<<i);
    if(x<n and sum+ bit[x]<v)
    {
      sum+=bit[x];
      cur+=(1<<i);
    }
  }
  return cur+1; 
}




// RANGE UPDATES POINT QUERIES

void add2(ll i,ll val)
{
  i++;

  for(i;i<=n;i+=i&(-i) )
    bit2[i]+=val;
}

void range_update2(ll l,ll r,ll val)
{
  add2(l,val);
  add2(r+1,-val);
}
void build2()
{
  for(ll i=0;i<n;i++)
    range_update2(i,i,a[i]);
}

ll query2(ll i)
{
  ll ans=0;
  i++;

  for(i;i>0;i-=(i&(-i)))
    ans+=bit2[i];

  return ans;
}



//  RANGE UPDATES RANGE QUERIES

void update3(vector<ll> &b,ll l ,ll val)
{
  l++;

  for(l;l<=n;l+=l&(-l))
  b[l]+=val;
}

void range_update3(ll l,ll r,ll x)
{
  update3(bit3,l,x);
  update3(bit3,r+1,-x);
  update3(bit4,l,x*(l-1));
  update3(bit4,r+1,-x*r);
}

void build3()
{
  for(ll i=0;i<n;i++) 
    range_update3(i,i,a[i]);
}

ll query3(vector<ll> &b,ll i)
{
  ll sum=0;
  for(++i;i>0;i-=(i&(-i)))
  sum+=b[i];
  return sum;
}

ll prefix_query3(ll i)
{
  return query3(bit3,i)*i-query3(bit4,i);
}

ll range_query3(ll l ,ll r)
{
  return prefix_query3(r)-prefix_query3(l-1);
}

//https://qr.ae/TW48hi




int main()
{ 
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    fast;

cin>>n;
// input
// 7
//1 4 2 7 12 11 13
for(ll i=0;i<n;i++)
cin>>a[i];

build();

cout<<range_query(2,6)<<endl;
 cout<<range_query(2,5)<<endl;
cout<<bit_search_height(5)<<endl;

cout<<endl;

build2();

range_update2(2,5,3);
cout<<query2(3)<<endl;
cout<<endl;

build3();

range_update3(2,5,3);
range_update3(3,6,2);
cout<<range_query3(2,6)<<endl;


}

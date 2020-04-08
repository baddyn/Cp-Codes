#include<bits/stdc++.h>
#define ll long long int
#define fast ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

ll n,m;
vector<vector<ll>> bit2d,a;

void update2d(ll i,ll j,ll x)
{
  i++,j++;

  for(i;i<=n;i+=i&(-i))
    for(ll k=j;k<=m;k+=k&(-k))
      bit2d[i][k]+=x;
}

void bit2d_build()
{
  for(ll i=0;i<n;i++)
    for(ll j=0;j<m;j++)
      update2d(i,j,a[i][j]);
}

ll query2d(ll x,ll y)
{
  x++,y++;
  ll sum=0;

  for(x;x>0;x-=x&(-x))
    for(ll z=y;z>0;z-=z&(-z))
      sum+=bit2d[x][z];

    return sum;
}

ll range_query2d(ll x1,ll y1,ll x2,ll y2)
{
  return (query2d(x2,y2)-query2d(x1-1,y2)-query2d(x2,y1-1)+query2d(x1-1,y1-1));
}



int main()
{ 
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    fast;

cin>>n>>m;
a.assign(n,vector<ll>(m));
bit2d.assign(n+5,vector<ll>(m+5,0));

for(ll i=0;i<n;i++)
  for(ll j=0;j<m;j++)
    cin>>a[i][j];

  /* input
  3 4
1 4 2 7 
12 11 13 14 
23 1 -2 3
  */

  bit2d_build();
  for(ll i=0;i<n+1;i++)
  {
    for(ll j=0;j<m+1;j++)
      cout<<bit2d[i][j]<<" ";
    cout<<endl;
  }

  cout<<range_query2d(1,1,2,3)<<endl;
  update2d(2,2,12);

  cout<<range_query2d(1,1,1,3)<<endl;
  cout<<range_query2d(1,1,2,3)<<endl;
  cout<<range_query2d(0,0,2,3)<<endl;

}

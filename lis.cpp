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

int main()
{ 
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

fast;
vector<ll> v={10,22,9,33,21,50,41,60,80};

vector<pair<ll,ll> > dp;
vector<ll> prev(200000);

for(ll i=0;i<v.size();i++)
{
  auto it=lower_bound(dp.begin(),dp.end(),mp(v[i],(ll)0));

  if(it==dp.end())
  {
    if(dp.empty())
      prev[i]=-1;
    else
    {
      it--;
      prev[i]=it->ss;
    }
    dp.pb({v[i],i});
  }
  else
    {
      it->ff=v[i],it->ss=i;
      if(it==dp.begin())
        prev[i]=-1;
      else it--,prev[i]=it->ss;
    }
}

//cout<<dp.size()<<endl;length of lis
vector<ll> lis;

ll z=*max_element(prev.begin(),prev.end());
lis.pb(v[max_element(prev.begin(),prev.end())-prev.begin()]);


while(z!=-1)
{
  lis.pb(v[z]);
  z=prev[z];
}
reverse(lis.begin(),lis.end());

for(ll i=0;i<lis.size();i++)
  cout<<lis[i]<<" ";
}

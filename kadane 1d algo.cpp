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

pair<ll,ll> kadane(vector<ll> &v)
{
  ll men=0,msf=-inf;
  ll start=0,end=0,temp=0;

  for(ll i=0;i<v.size();i++)
  {
    men+=v[i];

    if(msf<men)
    {
      msf=men;
      end=i;
      start=temp;
    }

    if(men<0)
    {
      men=0;
      temp=i+1;
    }
  }
  pair<ll,ll> p={start,end};
  return p;
}



int main()
{ 
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

vector<ll> v={-1,-1,1,-1};
pair<ll,ll> p=kadane(v);
cout<<p.ff<<" "<<p.ss<<endl;

}

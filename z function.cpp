#include<bits/stdc++.h>
#define ll  long long int
#define ull unsigned long long 
#define ff first
#define ss second
#define fast ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pb push_back 
#define mp make_pair
#define inf 1000000000000000
#define mod1 1000000009
#define mod2 998244353
#define ld long double
#define pll pair<ll,ll>
using namespace std;

vector<ll> zfn(string s)
{
    ll n=s.size();
    vector<ll> z(n,0);

    for(ll i=1,l=0,r=0;i<n;i++)
    {
        if(i<=r)z[i]=min(r-i+1,z[i-l]);
        while(i+z[i]<n and s[z[i]]==s[i+z[i]]) z[i]++;
        if(i+z[i]-1>r)l=i,r=i+z[i]-1;
    }
    return z;
}

void stringmatch(string txt,string pat,vector<ll>& occur)
{
    string s=pat+'*'+txt;
    vector<ll> z=zfn(s);

    ll p_size=pat.size(),t_size=txt.size();

    for(ll i=p_size+1;i<t_size+p_size+1;i++)
        if(z[i]==p_size)
            occur.pb(i-p_size-1);
}

int main()
{ 
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

fast;
ll t;
cin>>t;

while(t--)
{
   string s;
   cin>>s;

   vector<ll> z=zfn(s);

   // t1+t1+t2+t2=string find # of ways
   // vector<ll> z1=zfn(st);
   // reverse(st.begin(),st.end());
   // vector<ll> z2=zfn(st);
   // ll ans=0,n=st.size();

   // for(ll i=1;i<n-2;i+=2)
   // {
   // 	if(z1[i/2+1]>=i/2+1 and z2[(n-i)/2]>=(n-i)/2)
   // 		ans++;
   // }
   // cout<<ans<<'\n';


}
}

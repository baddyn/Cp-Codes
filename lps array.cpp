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

void lps(string s ,vector<ll>&pi)
{
    ll n=s.size();
    pi.assign(n,0);

    for(ll i=1;i<n;i++)
    {
        ll j=pi[i-1];
        while(j>0 and s[i]!=s[j])
            j=pi[j-1];
        if(s[i]==s[j])
            j++;
        pi[i]=j;
    }
}


void stringmatch(string txt,string pat,vector<ll>& occur)
{
    string s=pat+'*'+txt;
   vector<ll> pi;
   lps(s,pi);

   ll t_size=txt.size(),p_size=pat.size();

   for(ll i=p_size+1;i<t_size+p_size+1;i++)
    if(pi[i]==p_size)
        occur.pb(i-p_size-p_size);
}

ll uniq_substr(string s)
{
    ll n=s.size(),ans=1;

    for(ll i=1;i<n;i++)
    {
        string tmp=s.substr(0,i+1);
        reverse(tmp.begin(),tmp.end());

        vector<ll> pi;
        lps(tmp,pi);
        ll pimax=*max_element(pi.begin(),pi.end());
        ans=ans+i+1-pimax;
    }
    return ans;
}

vector<ll> prefixct(string s)
{
    vector<ll>pi;
    lps(s,pi);
    ll n=s.size();
    vector<ll> ans(n+1,0);

    for(ll i=0;i<n;i++)ans[pi[i]]++;
    for(ll i=n-1;i>0;i--)ans[pi[i-1]]+=ans[i];
    for(ll i=0;i<=n;i++) ans[i]++;
    return ans;

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

vector<ll> ans=prefixct(s);

for(ll i=1;i<=s.size();i++)
cout<<ans[i]<<" ";
}


}



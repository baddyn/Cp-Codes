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
ll pr1[1000000],pr2[1000000];
vector<ll> hash1,hash2;

void pre()
{
    pr1[0]=pr2[0]=1;
    for(ll i=1;i<1000000;i++)
        pr1[i]=(pr1[i-1]*31)%mod1,pr2[i]=(pr2[i-1]*53)%mod2;
}
void find_hash(string s)
{
    hash1.assign(s.size(),0),hash2.assign(s.size(),0);
    hash1[0]=hash2[0]=(s[0]-'a'+1);
    for(ll i=1;i<s.size();i++)
            hash1[i]=(hash1[i-1]+(s[i]-'a'+1)*pr1[i]%mod1)%mod1,hash2[i]=(hash2[i-1]+(s[i]-'a'+1)*pr2[i]%mod2)%mod2;
}

bool check_equal(ll l1,ll r1,ll l2,ll r2)
{
    //call hash_find in main for calculn of hash array once in o(n) 
    //and then this fn computes value in o(1)
    if(r1-l1!=r2-l2)
        return 0;
    if(l1==l2 and r1==r2)
        return 1;

    ll z1=0,z2=0;
    if(l1>0)z1=hash1[l1-1],z2=hash2[l1-1];
    ll val1=(hash1[r1]-z1+mod1)%mod1,val2=(hash2[r1]-z2+mod2)%mod2;

     z1=0,z2=0;
    if(l2>0)z1=hash1[l2-1],z2=hash2[l2-1];
    ll val3=(hash1[r2]-z1+mod1)%mod1,val4=(hash2[r2]-z2+mod2)%mod2;

    if(l1<l2)
        val1=(val1*pr1[l2-l1])%mod1,val2=(val2*pr2[l2-l1])%mod2;
    else
    val3=(val3*pr1[l1-l2])%mod1,val4=(val4*pr2[l1-l2])%mod2;

    if(val1==val3 and val2==val4)
        return 1;
    return 0;
}

//counts #uniq substrings in a string
ll uniq_substring(string s)
{
    find_hash(s);
    ll ct=0,n=s.size();

    for(ll len=1;len<=n;len++)
    {
        set<ll> sett1,sett2;

        for(ll i=0;i<=n-len;i++)
        {
            ll z1=0,z2=0;
            if(i>0)z1=hash1[i-1],z2=hash2[i-1];
            ll curh1=(hash1[i+len-1]-z1+mod1)%mod1,curh2=(hash2[i+len-1]-z2+mod2)%mod2;
            curh1=(curh1*pr1[n-i-1])%mod1,curh2=(curh2*pr2[n-i-1])%mod2;
            sett1.insert(curh1),sett2.insert(curh2);
        }
        ct=ct+min(sett1.size(),sett2.size());
    }
    return ct;
}

void rabinkarp(string pat,string txt,vector<ll>&occur)
{
    find_hash(txt);
    ll p_size=pat.size(),t_size=txt.size(),sh1=0,sh2=0;

    for(ll i=0;i<p_size;i++)
        sh1=(sh1+(pat[i]-'a'+1)*pr1[i]%mod1)%mod1,sh2=(sh2+(pat[i]-'a'+1)*pr2[i]%mod2)%mod2;

    for(ll i=0;i<t_size+1-p_size;i++)
    {
        ll z1=0,z2=0;
        if(i>0)z1=hash1[i-1],z2=hash2[i-1];

        ll curh1=(hash1[i+p_size-1]-z1+mod1)%mod1,curh2=(hash2[i+p_size-1]-z2+mod2)%mod2;

        if(curh1==sh1*pr1[i]%mod1 and curh2==sh2*pr2[i]%mod2)occur.pb(i);
    }
}

int main()
{ 
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

fast;
pre();

ll t;
cin>>t;

while(t--)
{
    string txt,pat;
    cin>>txt>>pat;
    vector<ll> occur;

    rabinkarp(pat,txt,occur);

    if(occur.empty())
        cout<<"Not Found"<<'\n'<<'\n';
    else
    {
        cout<<occur.size()<<'\n';
        for(auto i:occur)
            cout<<i+1<<" ";
        cout<<'\n'<<'\n';
    }
}
}

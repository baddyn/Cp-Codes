#include<bits/stdc++.h>
#define ll long long int
#define ull unsigned long long int
#define ff first
#define ss second
#define fast ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pb push_back 
#define mp make_pair
#define inf 2000000009
#define mod 1000000007
using namespace std;

ll gcd(ll a ,ll b)
{	if( !b)
	 return a;
	return gcd(b,a%b);
}


ll ext_gcd(ll a, ll b,ll& x,ll& y)
{
 if(!a)
 {
 	x=0;
 	y=1;
 	return b;
 }
 ll x1,y1;
 ll d=ext_gcd(b%a,a,x1,y1);
 x=y1-(b/a)*x1;
 y=x1;
 return d;
}

bool dio_solution(ll a,ll b, ll c, ll &x, ll& y,ll & g)
{  
	if(a==0 and b==0)
	{   x=1;y=1;
		if(c==0)
			return 1;
		else return 0;
	}

	g=ext_gcd(abs(a),abs(b),x,y);
	if(c%g)
		return 0;

	x*=c/g;
	y*=c/g;
	if(a<0) x=-x;
	if(b<0) y=-y;
	return 1;
}


ll bin_exp(ll a,ll b)
{
	ll ans=1;
	if(a==0)
		ans=1;

	while(b>0)
	{
		if(b&1)
			ans*=a;

		a*=a;
		b>>=1;
	}
	return ans;
}


ll bin_exp_mod(ll a, ll b,ll m)
{
	a%=m;
	ll ans=1;
	if(a==0) ans=0;

	while(b>0)
	{
		if(b&1) ans=(ans*a)%m;
		a=(a*a)%m;
		b>>=1;
	}
	return ans;
}


ll bin_exp_mod_prime(ll a, ll b,ll m)
{
	// x^n modm =x^((m-1)(k)+ w) modm
	//=x^(m-1)(k) modm*(x^w)modm
	//as x^m-1 =1modm
	//=1*(x^w)modm=x^w modm 
	//= x^(n mod m-1)mod m
	a%=m;
	b%=(m-1);
	ll ans=1;
	if(a==0)
		ans=0;

	while(b>0)
	{
		if(b&1)
			ans=(ans*a)%m;
		a=(a*a)%m;
		b>>=1;
	}
	return ans;
}


ll  when_ab_overflow(ll a, ll b,ll m)
{
  a=a%m;
  b=b%m;
  ll ans=0;

  while(b>0)
  {
    if(b&1)
      ans=(ans+a)%m;
    a=(a*2)%m;
    b>>=1;

  }
  return ans;
}


ll euler_tot(ll n)
{
	ll ans=n;

	for(ll i=2;i*i<=n;i++)
	{
		if(n%i==0)
		{
			while(n%i==0)
				n/=i;
			ans-=ans/i;
		}
	}

	if(n>1)
		ans-=ans/n;
	return ans;
}

void euler_totient_range(ll n)
{
	ll phi[n+1];

	for(ll i=0;i<=n;i++)
		phi[i]=i;

	for(ll i=2;i<=n;i++)
	{
		if(phi[i]==i)
		{
			phi[i]=i-1;
			for(ll j=i+i;j<=n;j+=i)
				phi[j]-=phi[j]/i;
		}
	}

	for(ll i=2;i<=n;i++)
		cout<<i<<" "<<phi[i]<<endl;
}


bool checkprime(ll n)
{
    if(n<=1)
    return false;

     if(n<=3)
    return true;

    else if(n%2==0 or n%3==0)
    return false;

    else 
    {
        for(ll i=5;i*i<=n;i+=6)
    if(n%i==0 or n%(i+2)==0)
    return false;
    }

    return true;
}


ll prime_sieve(ll n)
{
    vector<bool> prime(n+1,true);
    prime[0]=prime[1]=false;
  
 for(ll i=2;i*i<=n;i++)
 {
    if(prime[i])
        for(ll j=i*i;j<n+1;j+=i)
            if(prime[j]==1)
            	prime[j]=i;
 }

for(ll i=2;i<n+1;i++)
    if(prime[i])
        cout<<i<<endl;
 }

void segmented_sieve(ll l ,ll r)
{
	// segmented sieve code in folder
}

    void divisors(ll n)
	{
		vector<ll> v;
		ll x=sqrt(n);
		for(ll i=1;i<=x;i++)
		{
			if(n%i==0)
			{
			 v.pb(i);
			 if(i!=n/i)
				v.pb(n/i);
			}
		}

		for(auto i:v)
			cout<<i<<" ";
		cout<<endl;
	}

	//diviosrs for 1 to n iterate on all n upto n/2 and push the
	//element on all its multiples

	// for range l-r divisors iterate on all numbers from 1 to sqrt(r)
	// push element in its multiple and n/element
	//ex 18 run loop 1-4 
	// 1-18 ,2-9 ,3-6 ans
void inverse calculation(ll n)
{
    ll fact[n+5],inv[n+5],finv[n+5];
    fact[0]=fact[1]=inv[0]=inv[1]=finv[0]=finv[1]=1;
  

    for(ll i=2;i<n+5;i++)
    {
      fact[i]=fact[i-1]*i%mod;
      inv[i]=mod-inv[mod%i]*(mod/i)%mod;
      finv[i]=finv[i-1]*inv[i]%mod;
    }
}


ll nCr(int n, int r)
{
    if (n < 0 or n<r or r<0) return 0;
    return (fact[n] * finv[r] % mod) * finv[n-r] % mod;
}

int main()
{ 
  fast;

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
  ll x,y,g; 
cout<<ext_gcd(17,3,x,y)<<endl<<gcd(0,42)<<endl<<gcd(42,49)<<endl<<gcd(49,42)<<endl;
cout<<x<<y<<endl;
//cout<<dio_solution1(-3,-2,2,x,y,g)<<endl<<x<<endl<<y<<endl<<g;

cout<<euler_tot(49)<<endl;
divisors(56);





}



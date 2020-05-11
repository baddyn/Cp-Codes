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
vector<ll> ans1,ans2,ans3,a;
ll n,m;
/*Finding the minimum for all subarrays of fixed length

Suppose we are given an array A
of length N and a given M≤N. We have to find the minimum of each subarray of length M in this array, i.e. we have to find:
min0≤i≤M−1A[i],min1≤i≤MA[i],min2≤i≤M+1A[i], … ,minN−M≤i≤N−1A[i]*/

void fun1()
{
    deque<ll> q;

    for(ll i=0;i<m;i++)
    {
        while(!q.empty() and q.back()>=a[i])
            q.pop_back();
            q.push_back(a[i]);
    }
    ans1.pb(q.front());

    for(ll i=m;i<n;i++)
    {
        if(q.front()==a[i-m])
            q.pop_front();
         while(!q.empty() and q.back()>=a[i])
            q.pop_back();
            q.push_back(a[i]);
            ans1.pb(q.front());
    }
}

void fun2()
{
    deque<pair<ll,ll> > q;
    ll add=0,remove=0;

    for(ll i=0;i<m;i++)
    {
        while(!q.empty() and q.back().ff>=a[i])
            q.pop_back();
        q.push_back({a[i],add});
        add++;
    }
    ans2.pb(q.front().ff);
    for(ll i=m;i<n;i++)
    {
        if(!q.empty() and q.front().ss==remove)
            q.pop_front();
        remove++;

        while(!q.empty() and q.back().ff>=a[i])
            q.pop_back();

        q.push_back({a[i],add});
        add++;

        ans2.pb(q.front().ff);
    }
}

void fun3()
{
    stack<pair<ll,ll> > st1,st2;
    for(ll i=0;i<m;i++)
    {
        if(st1.empty())
            st1.push({a[i],a[i]});
        else
            st1.push({a[i],min(a[i],st1.top().ss)});
    }

    ans3.pb(st1.top().ss);

    for(ll i=m;i<n;i++)
    {
        if(st2.empty())
        {
            while(!st1.empty())
            {
                ll el=st1.top().ff;
                st1.pop();
                ll mn=el;
                if(!st2.empty())
                 mn=min(mn,st2.top().ss);
             st2.push({el,mn});
            }
        }
        st2.pop();

        if(st1.empty())
            st1.push({a[i],a[i]});
        else
            st1.push({a[i],min(a[i],st1.top().ss)});

        if(st1.empty())
            ans3.pb(st2.top().ss);
        else if(st2.empty())
            ans3.pb(st1.top().ss);
        else
            ans3.pb(min(st1.top().ss,st2.top().ss));

    }
}
int main()
{ 
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

fast;

cin>>n>>m;
a.assign(n,0);
for(ll i=0;i<n;i++) 
cin>>a[i];

fun1();
for(auto i:ans1)
cout<<i<<" ";
cout<<endl;

fun2();
for(auto i:ans2)
cout<<i<<" ";
cout<<endl;

fun3();
for(auto i:ans3)
cout<<i<<" ";
cout<<endl;


}

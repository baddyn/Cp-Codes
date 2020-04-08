#include<bits/stdc++.h>
#define ll  long long int
#define ff first
#define ss second
#define mp make_pair
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds;
#define pbdm tree<pair<ll,ll>, null_type, less<pair<ll,ll> >, rb_tree_tag, tree_order_statistics_node_update> 
#define pbds tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> 

int main()
{
    pbds s;
    
    for(ll i=1;i<8;i++)
    s.insert(i*i);
    
    for(auto i:s)
    cout<<i<<" ";
    cout<<endl;
    
    cout<<s.size()<<endl;
    
 cout<<*s.find_by_order(2)<<endl;
 
 cout<<s.order_of_key(10)<<endl;
 
 s.erase(3);
  // 3 doesnt exist so no effect
    
    s.erase(4);
    //4 exists so erased
     
    for(auto i:s)
    cout<<i<<" ";
    cout<<endl;
    
    cout<<*s.upper_bound(16)<<endl<<*s.lower_bound(16)<<endl;
    
    
    //pbdm now
    
    pbdm ms;
    
    for(ll i=1;i<8;i++)
    ms.insert(mp(i*i,i));
    
     ms.insert(mp(4,8));
      ms.insert(mp(4,9));
    
    for(auto i:ms)
    cout<<i.ff<<" "<<i.ss<<endl;
   
    cout<<ms.size()<<endl;
    
    ms.erase(ms.lower_bound({4,0}));
    
    cout<<ms.size()<<endl;
    
    //cout<<*ms.find_by_order(2)<<endl;
    cout<<ms.order_of_key({17,0})<<endl;
    
    cout<<ms.find_by_order(2)->ff;
    

 
}

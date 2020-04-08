#include<bits/stdc++.h>
#define ll  long long int
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds;
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
 
}

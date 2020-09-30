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
    
    // 1 4 9 16 25 36 49 
    
    cout<<s.size()<<endl;
    
 cout<<*s.find_by_order(2)<<endl;
 //9 
 
 cout<<s.order_of_key(10)<<endl;
 //3,index of 10 if exist else of larger than it
 
 s.erase(3);
  // 3 doesnt exist so no effect
    
    s.erase(4);
    //4 exists so erased
     
    for(auto i:s)
    cout<<i<<" ";
    cout<<endl;
    // 1 9 16 25 36 49 
    
    
    cout<<*s.upper_bound(16)<<endl<<*s.lower_bound(16)<<endl;
    // 25 ,16 output
    
    
    //pbdm now
    cout<<"pbdm noe "<<endl;
    
    pbdm ms;
    
    for(ll i=1;i<8;i++)
    ms.insert(mp(i*i,i));
    
     ms.insert(mp(4,8));
      ms.insert(mp(4,9));
    
    for(auto i:ms)
    cout<<i.ff<<" "<<i.ss<<endl;
    
    //     1 1
// 4 2
// 4 8
// 4 9
// 9 3
// 16 4
// 25 5
// 36 6
// 49 7
    
    
   
    cout<<ms.size()<<endl;
    //9 
    

    
    ms.erase(ms.lower_bound({4,0})); // remove(4,2)
    
    for(auto i:ms)
    cout<<i.ff<<" "<<i.ss<<endl;
    
//     1 1
// 4 8
// 4 9
// 9 3
// 16 4
// 25 5
// 36 6
// 49 7
    
    
    cout<<ms.size()<<endl;
    //8
    
    
    cout<<ms.order_of_key({17,0})<<endl;
    // 5
    
    auto itr=ms.find_by_order(2);
    
    
    cout<<itr->ff<<" "<<itr->ss<<endl;
    // 4 9
    

 
}

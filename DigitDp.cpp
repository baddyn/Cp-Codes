/// How many numbers x are there in the range a to b, where the digit d occurs exactly k times in x?

#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll dp[13][13][2];
vector<int> num;
ll a,b,d,k;
/// DP[p][c][f] = Number of valid numbers <= b from this state
/// p = current position from left side (zero based)
/// c = number of times we have placed the digit d so far
/// f = the number we are building has already become smaller than b? [0 = no, 1 = yes]

ll fun(ll pos, ll count, bool flag){
    
   if(count>k)
   return 0;
   
   if(pos==num.size()){
       return count==k;
   }
   
   if(dp[pos][count][flag]!=-1)
   return dp[pos][count][flag];
   
   
   ll res=0, limit=9;
   
   if(flag==0){
       limit=num[pos];
   }
   
   for(int digit=0;digit<limit+1;digit++){
       int newflag=flag;
       int newcount=count;
       
       if(flag==0 and digit<limit)
       newflag=1;
       
      if(digit==d)
      newcount++;
      
      if(newcount<=k)
      res+=fun(pos+1,newcount,newflag);
   }
   
   return dp[pos][count][flag]=res;
    
    
}

ll solve(ll b){
    num.clear();
    while(b>0){
        num.push_back(b%10);
        b/=10;
    }
    reverse(num.begin(), num.end());
    /// Stored all the digits of b in num for simplicity

    memset(dp, -1, sizeof(dp));
    return fun(0, 0, 0);
}


int main(){
    
    cin>>a>>b>>d>>k;
    
    cout<<solve(b)-solve(a-1);
}

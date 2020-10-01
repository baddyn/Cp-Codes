#include<bits/stdc++.h>
using namespace std;

double f(double x)
{ return -(x*x)+(2*x)+3;}

double tsearch(double l,double r)
{
  for(int i=0;i<50;i++)
   {double z=(r-l)/3;
    double m1=l+z;
    double m2=l+(2*z);
    
    if(f(m1)>f(m2))
     r=m2;
    else l=m1;
     }
    cout<<l<<endl<< f(l);
    
}
     
     int main()
     { 
      #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    double l,r;
     cin>>l>>r;
     tsearch(l,r);
     }

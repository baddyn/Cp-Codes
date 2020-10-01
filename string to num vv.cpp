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

int main()
{ 
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
fast;

cout<<"STRING TO NUM METHODS"<<endl;

// string s="123.45877766765564565465464646643656575675675675465656756757";

// cout<<fixed<<setprecision(30)<<stoi(s)<<endl<<stof(s)<<endl<<stoll(s)<<endl<<stod(s)<<endl;
// // stof rounds off 


// stringstream myobj(s),myobj1(s);
// int x;
// double y;
// myobj>>x;
// myobj1>>y;
// cout<<fixed<<setprecision(30)<<x<<endl<<y<<endl;
 


// string t="when i am       moved    ";
// stringstream itr(t);
// string ans;
// string temp;
// while(itr>>temp)
// {
// 	ans+=temp;
// }
// cout<<ans<<endl;




// string s1="123.456";
// int f=0;

// for(int i=0;i<s1.size();i++)
// {
// 	if(s1[i]!='.')
// 	{
// 		f=f*10 +int(s1[i]-'0');
// 	}

// 	else  break;
// }
// cout<<f<<endl;
// cout<<"NOW FOR FLOAT"<<endl;

// float f1=0;
// for(int i=0;i<s1.size();i++)
// {
// 	if(s1[i]!='.')
// 		f1=f1*10+int(s1[i]-'0');
// 	else
// 	{
// 		i++;
// 		float temp=0;
// 		int val=1;
// 		while(i<s1.size())
// 		{
// 			temp=temp*10+int(s1[i]-'0');
// 			val*=10;
// 			i++;
// 		}
// 		cout<<temp<<endl;
// 		temp/=val;
// 		cout<<f1<<endl<<temp<<endl;
// 		f1+=temp;
// 	}
// }
// cout<<f1<<endl;





cout<<"NOW NUM TO STRING METHODS"<<endl<<endl;


ll num=1234231312;

// creates issue with float double 
ostringstream object;
object<< num;

string q=object.str();
cout<<q<<endl;


// // doesnt work in sublime but works on online latest compilers
// ld number=1221.121212;
// ll numbercopy=number;

// // string mystring=to_string(number);
// // cout<<mystring<<endl;
// string qw=to_string(numbercopy);
// cout<<qw<<endl;


cout<<"now char to number and vice versa"<<endl<<endl;

char ch='9';
int xe=ch-'0';
cout<<xe<<endl;

int nu=9;
string w=to_string(nu);
cout<<w<<endl;

char ch1=char(nu+'0');
cout<<ch1<<endl;

}

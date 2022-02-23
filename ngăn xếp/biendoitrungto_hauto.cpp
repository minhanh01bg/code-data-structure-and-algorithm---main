#include<bits/stdc++.h>
	#define reset(x) memset(x,0,sizeof((x)))
	#define SZ(a) (int((a).size()))
	#define ALL(a) a.begin(), a.end()
	#define PB push_back
	#define MP make_pair
	#define LL long long
	#define LD long double
	#define II pair<int, int>
	#define X first
	#define Y second
	#define VI vector<int>
	const int N = 100005;
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define REP(i, a, b) for(int i = (a); i <=(b); i++)
#define FORD(i, a, b) for(int i = (a); i > (b); i--)
#define REPD(i, a, b) for(int i = (a); i >=(b); i--)
#define TR(it, a) for(typeof((a).begin()) it = (a).begin(); it != (a).end(); ++it)
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define BEGIN int t;cin>>t;while(t--)
using namespace std;
/*
//dem số bit 1
ll findsize(ll n){
	if(n==0) return (ll)1;
	if(n==1) return (ll)1;
	ll size=2*findsize(n/2)+1;
	return size;
}

ll bit1(ll n, ll l, ll r){
	if(n<=1) return n;
	ll res=0;
	ll m=n/2;
	ll size_m=findsize(m);
	if(l<=size_m) res+=bit1(n/2,l,min(size_m,r));// tim ben trai
	if(l<=size_m+1 && size_m+1<=r) res+= n%2;// == vt trung tam
	if(size_m+1<r) res+=bit1(n/2, max((ll)1, l-size_m-1), r-size_m-1);// tim ben doi xung
	return res;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
    cin>>t;
    ll n,l,r;
    while(t--){
    	cin>>n>>l>>r;
		cout<<bit1(n,l,r);
        cout<<endl;
    }
	return 0;
}*/

//DSA07008 - BIẾN ĐỔI TRUNG TỐ - HẬU TỐ
#include<bits/stdc++.h>
using namespace std;

bool Toanhang(char c){
	if((c>='a' && c<='z')
	||(c>='A' && c<='Z'))
	{
		return true;
	}
	else return false;
}

bool Toantu(char c){
	if(c=='+'||c=='-'||c=='*'||c=='/'||c=='^')
	{
		return true;
	}
	else return false;
}

int Uutien(char c){
	if(c == '^') return 3;
    else if (c == '*' || c == '/') return 2;
    else if (c == '+' || c == '-') return 1;
    else return -1; 
}
void process(){
	string s;
	cin>>s;
	string res;
	stack<char> mo;	
	FOR(i,0,s.length())
	{
		if(Toanhang(s[i]))
		{
			res+=s[i];
		}else if(s[i]=='('){
			mo.push(s[i]);	
		}else if(s[i]==')'){
			while((mo.top()!='(') && (!mo.empty()))
			{
				char tmp=mo.top();
				res+=tmp;
				mo.pop();
			}
			if(mo.top()=='(')
			{
				mo.pop();
			}
		}else if(Toantu(s[i])){
			if(mo.empty()){
				mo.push(s[i]);
			}
			else
			{
				if(Uutien(s[i])>Uutien(mo.top())){
					mo.push(s[i]);
				}
				else if((Uutien(s[i])==Uutien(mo.top()))&& s[i]=='^')
				{	
					mo.push(s[i]);
				}
				else
				{
					while(!mo.empty()&&Uutien(s[i])<=Uutien(mo.top()))
					{
						char temp=mo.top();
						res+=temp;
						mo.pop();
					}
					mo.push(s[i]);
				}	
			}	
		}
	}		
	while(!mo.empty()){
		res+=mo.top();
		mo.pop();
	}
	cout<<res;
	cout<<endl;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		process();
	}
	return 0;
}
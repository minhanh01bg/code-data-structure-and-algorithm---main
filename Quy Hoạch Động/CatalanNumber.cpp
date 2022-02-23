#include<bits/stdc++.h>
#define ll long long
#define run() int t;cin>>t;while(t--)
#define fast() ios_base::sync_with_stdio(0);cin.tie(0);

// typedef long long ll;
// typedef vector<int> BigInt;
#define pob pop_back
#define EL printf("\n")
#define pb push_back
#define FOR(i,l,r) for (int i=l;i<=r;i++)
#define FORD(i,r,l) for (int i=r;i>=l;i--)
using namespace std;
string a[1001];
string add(string x,string y){
	string res="";
	while(x.length() < y.length()) x="0"+x;
	while(y.length() < x.length()) y="0"+y;
	int nho = 0; 
	FORD(i, x.size()-1, 0){
		int tmp = int(x[i] - '0') + int(y[i]-'0') + nho;
		nho = tmp/10;
		tmp = tmp%10;
		res = (char)(tmp + '0') + res;
	}
	if(nho > 0) res = char(nho + '0') + res;
	return res;
}
string mul(string x, string y) {
	int k = x.length() + y.length();
	int c[k];
	int t;
	for(t=0;t<k;t++) c[t]=0;
	for(int i=x.length()-1;i>=0;i--) {
		if(x[i]==48) continue;
		for(int j=y.length()-1;j>=0;j--) {
			if(y[j]==48) continue;
			t=k-1-x.length()+1+i-y.length()+1+j;
			int p=((int)x[i]-48)*((int)y[j]-48);
			while(p>0){
				c[t]+=p%10;
				p/=10;
				p+=c[t]/10;
				c[t]%=10;
				t--;
			}
		}
	}
	int d=0;
	while(d<k&&c[d]==0) d++;
	if(d==k) return "0";
	else {
		 string s = "";
		 for(int i=d;i<k;i++) s+= char (c[i] + 48);
		 return s;
	}
}

void slove(){
	a[0]="1";
	a[1]="1";
	FOR(i,2,100){
		string tmp = "";
		FOR(j, 0, i-1){
			string tmp1 = "0";
			tmp = add(tmp,mul(a[j],a[i-j-1]));
		}
		a[i] = tmp;
	}
}

int main(){
	slove();
	fast();
	run(){
		int n;
		cin >> n;
		cout << a[n] << endl;
	}	
}
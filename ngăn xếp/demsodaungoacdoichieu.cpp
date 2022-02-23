#include <bits/stdc++.h>
#define ll long long
#define FOR(i, a, b) for (ll i = a; i <= b; i++)
#define FORD(i, a, b) for (ll i = a; i >= b; i--)
#define run() int t;cin>>t;while(t--)
#define fast() ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
int mi(string str){
	stack<char> s;
	
	FOR(i,0,str.length()-1){
		if(str[i] == ')' && !s.empty()){
			if(s.top() == '(')
				s.pop();
			else s.push(str[i]);
		}
		else s.push(str[i]);
	}
	int len = s.size(), n = 0, m = 0;
	while(!s.empty()){
		if(s.top() == '(')
			m++;
		else n++;
		s.pop();
	}
	return (n/2 + m/2 + n%2 + m%2);
}
int main(){
	fast();
	run() {
		string str;
		cin >> str;
		cout << mi(str) << endl;
	}
}
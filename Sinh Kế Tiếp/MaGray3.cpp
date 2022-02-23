#include<bits/stdc++.h>

using namespace std;
//MÃ GRAY 3
#define run() int t;cin>>t;while(t--)
#define fast() ios_base::sync_with_stdio(0);cin.tie(0);
#define ll long long 
#define endl "\n"
int main(){
	run(){
		string s;
		cin>>s;
		cout<<s[0];
		for(int i=1;i<s.size();i++){
			if(s[i]!=s[i-1]) cout<<1;
			else cout<<0;
		}
		cout<<endl;
	}
}
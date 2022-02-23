#include<bits/stdc++.h>

using namespace std;
//MÃ GRAY 2
#define run() int t;cin>>t;while(t--)
#define fast() ios_base::sync_with_stdio(0);cin.tie(0);
#define ll long long 
#define endl "\n"
int main(){
	run(){
		string s;
		cin>>s;string s1;
		if(s[0]=='0')
			s1="0";
		else s1="1";
		for(int i=1;i<s.size();i++){
			int x=s1.size()-1;
			if(s1[x]!=s[i]) s1+="1";
			else s1+="0";
		}
		cout<<s1;
		cout<<endl;
	}
}
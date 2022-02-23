#include <bits/stdc++.h> 
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
	int Q,x;
	string s;
	cin>>Q;
	queue<int> mo;
	while(Q--){
		cin>>s;
		if(s=="PUSH"){
			cin>>x;
			mo.push(x);
		}else if(s=="PRINTFRONT"){
			if(mo.size()>0) cout<<mo.front();
			else if(mo.empty()) cout<<"NONE";
		}else if(s=="POP"){
			if(mo.size()>0)	mo.pop();
		}
		cout<<endl;
	}
	return 0;
}
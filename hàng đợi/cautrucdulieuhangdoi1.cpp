#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
	int t,n;
	cin>>t;
	while(t--){
		cin>>n;
		queue<int> m;
		int x;
		while(n--){
			cin>>x;
			if(x==1) cout<<m.size();
			else if(x==2){
				if(m.size()>0)cout<<"NO";
				else if(m.empty())cout<<"YES";
			}
			else if(x==3){
				int so;
				cin>>so;
				m.push(so);
			}
			else if(x==4 && m.size()>0) m.pop();
			else if(x==5){
				if(m.size()>0) cout<<m.front();
				else cout<<-1;
			}
			else if(x==6){
				if(m.size()>0) cout<<m.back();
				else cout<<-1;
			}
			cout<<endl;
		}
		cout<<endl;
	}
	return 0;
}
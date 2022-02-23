#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
		cin>>n;
        int truoc[n+1];
        memset(truoc,0,sizeof(truoc));
		int u,v;     
        for(int i=1;i<=n-1;i++){
        	cin>>u>>v;
        	truoc[v]=u;
		}
		for(int i=1;i<=n;i++){
			bool ok=true;
			for(int j=1;j<=n;j++){
				if(truoc[j]==i) ok=false;
			}
			if(ok==true){
				stack<int> p;
				p.push(i);
				int k=i;
				while(truoc[k]){
					p.push(truoc[k]);
					k=truoc[k];
				}
				while(!p.empty()){
					cout<<p.top()<<" ";
					p.pop();
				}
				cout<<endl;
			}
		}
    }
    return 0;
}   
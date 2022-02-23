#include<bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;

int n;
int S;
int a[31];
int res = 9999;
 
void Try(int i , ll sum , int d){
	if (sum>S || d>res) return;	
	if(i==n){
		if (sum == S) res = min(res,d);
		return;
	}
	Try(i+1,sum,d);
	Try(i+1,sum+a[i],d+1);
}
 
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        cin>>S;
        res=9999;
        for(int i=0;i<n;i++) cin>>a[i];
        Try(0,0,0);
        if (res==9999) cout<<-1;
        else cout<<res;
        cout<<endl;
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
//123	DSA02013	SỐ NGUYÊN TỐ
#define FOR(i, a, b) for(int i=a;i<=b;i++)
#define fast() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define BEGIN() int t;cin>>t;while(t--)
vector< vector<int> > res;
int a[100];
int N,P,S;

bool nt(int n){
	if(n<2) return false;
	for(int i=2;i<=sqrt(n);i++){
		if(n%i==0) return false;
	}
	return true;
}

int v[100],n;
void khoitao(){
	cin>>N>>P>>S;
	n=0;
	for(int i=S;i>P;i--){
		if(nt(i)){
			n+=1;
			v[n]=i;	
		}
	}
	sort(v+1,v+n+1);
}

void Try(int i){
    for(int j=a[i-1]+1; j<=n-N+i; j++){ 
        a[i]=j;
  	    if(i==N){
        	int sum=0;
        	for(int l =1;l<=N;l++){
        		if(a[l]) sum+=v[a[l]];
			}
			if(sum==S ){
				vector<int> x;
				for(int l=1;l<=N;l++){
					x.push_back(v[a[l]]);
				}
				res.push_back(x);
			}
		}
        else Try(i+1);
    }
}

int main(){
	fast()
	BEGIN(){
    	res.clear();
        khoitao();
        Try(1);
        sort(res.begin(),res.end());
        cout<<res.size()<<endl;
        for(int i=0;i<res.size();i++){
        	for(int j=0;j<res[i].size();j++){
        		cout<<res[i][j]<<" ";
			}
			cout<<endl;
		}
        cout<<endl;
    }
	return 0;
}
/*
2
2  7  28
3  2  23
*/
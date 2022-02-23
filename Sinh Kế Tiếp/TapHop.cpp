#include<bits/stdc++.h>
using namespace std;

int n,k,s,dem;
//1<=n<=20, 1<=k<=10 và 1<=s<=155
int a[11];
//a[k+1]
void Try(int i){
	for(int j=a[i-1]+1;j<=n-k+i;j++){
		a[i]=j;
		if(i==k){
			int sum=0;
			for(int l=1;l<=k;l++){
				sum+=a[l];
			}
			if(sum==s) dem++;
		}
		else Try(i+1);
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
//    int t;
//    cin>>t;
    while(1){
		cin>>n>>k>>s;
		dem=0;
		for(int i=0;i<11;i++) a[i]=0;
		if(n==0 && k==0 && s==0) break;
		Try(1);
		cout<<dem;
		cout<<endl;
	}
	return 0;
}
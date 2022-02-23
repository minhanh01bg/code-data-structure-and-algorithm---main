#include <bits/stdc++.h>
using namespace std;

int main(){
	int t; cin>>t;
	while(t--){
		string s;
		long long n,k; 
		cin>>s>>k;
		n=s.size();
		while(k>n) n*=2;
		while(n>s.size()){
			if(k>n/2){
				k-=n/2; // tim o chuoi sao chep
				if(k>1) k-=1; // ki tu thu k o k-1 cua chuoi sao chep
				else k=n/2;// cuoi chuoi ban dau
			}
			n/=2;
		}
		cout<<s[k-1]<<endl;
	}
	return 0;
}
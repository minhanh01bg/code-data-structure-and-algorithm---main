// 124	DSA02017	SẮP XẾP QUÂN HẬU 2
    #include<bits/stdc++.h>
using namespace std;	
#define FOR(i, a, b) for(int i=a;i<=b;i++)
#define fast() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define BEGIN() int t;cin>>t;while(t--)
bool h[11],c[11],xuoi[22],nguoc[22];
//xuoi=i+j-1, nguoc=i-j+n
int res;
int a[11];// mang danh dau
int v[11][11];// ban co

void Try(int i){
	for(int j=1;j<=8;j++){
		if(h[j]==false && c[j]==false && xuoi[i+j-1]==false && nguoc[i-j+8]==false){
			a[i]=j;
			h[j]=c[j]=xuoi[i+j-1]=nguoc[i-j+8]=true;
			if(i==8){
				int sum=0;
				for(int l=1;l<=8;l++){
					sum+=v[l][a[l]];
				}
				res=max(res,sum);
			}
			else Try(i+1);
			h[j]=c[j]=xuoi[i+j-1]=nguoc[i-j+8]=false;
		}
	}
}

int main(){
    fast()
	BEGIN(){
		for(int i=1;i<=8;i++){
			for(int j=1;j<=8;j++){
				cin>>v[i][j];
			}
		}
		for(int i=1;i<11;i++) h[i]=c[i]=false;
		for(int i=1;i<22;i++) xuoi[i]=nguoc[i]=false;
		res=0;
		Try(1);
		cout<<res;
		cout<<endl;
	}
	return 0;
}

/*
1
1  2  3  4  5  6  7  8
9  10 11 12 13 14 15 16
17 18 19 20 21 22 23 24
25 26 27 28 29 30 31 32
33 34 35 36 37 38 39 40
41 42 43 44 45 46 47 48
49 50 51 52 53 54 55 56
57 58 59 60 61 62 63 64
*/
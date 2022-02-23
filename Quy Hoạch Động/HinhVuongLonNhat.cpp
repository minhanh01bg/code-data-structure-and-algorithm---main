#include<bits/stdc++.h>

#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define REP(i, a, b) for(int i = (a); i <=(b); i++)
#define FORD(i, a, b) for(int i = (a); i > (b); i--)
#define REPD(i, a, b) for(int i = (a); i >=(b); i--)
#define TR(it, a) for(typeof((a).begin()) it = (a).begin(); it != (a).end(); ++it)
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define BEGIN int t;cin>>t;while(t--)
#define reset(x) memset(x,0,sizeof((x)))
#define SZ(a) (int((a).size()))
#define ALL(a) a.begin(), a.end()
#define PB push_back
#define MP make_pair
#define LL long long
#define LD long double
#define II pair<int, int>
#define X first
#define Y second
#define VI vector<int>
const int N = 100005;
using namespace std;
#define mo 1000000007
/*
int main(){
    FAST
	long long n,k;
	BEGIN {
		cin>>n>>k;
		long long sum=1;
		if(k>n) sum=0;
		REP(i,n-k+1,n){
			sum*=i;
			sum%=mo;
		}
		cout<<sum;
		cout<<endl;
	}
	return 0;
}*/
/*
int main(){
    FAST
    BEGIN{
        int n,a,b,c;
        cin>>n>>a>>b>>c;
        int dp[n+1];
        dp[0]=0;
        dp[1]=a;
        REP(i,2,n){
            if(i & 1) dp[i] = min(dp[i-1]+a, dp[(i+1)/2]+c+b);
            else dp[i] = min(dp[i/2] + c, dp[i-1] + a);
        }
        cout<<dp[n]<<endl;
    }  
    return 0;
}*/
// tim chuoi con chung dai nhat, kq = do dai chuoi - do dai chuoi con
/*
int main(){
	FAST
    BEGIN{
		string a;
		cin>>a;
		string b=a;
		reverse(b.begin(),b.end());//dao nguoc
		int n=a.length();
		int c[n+1][n+1];
		REP(i,0,n){
			REP(j,0,n){
				if(i==0 || j==0) c[i][j]=0;
				else if(a[i-1]==b[j-1]){
					c[i][j]=c[i-1][j-1]+1;
				} 
				else c[i][j]=max(c[i][j-1],c[i-1][j]);
			}
		}
		cout<<n-c[n][n]<<"\n";
	}
	return 0;
}*/
/*
// Cặp nghịch thế

LL merge(LL arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
    i = 0; 
    j = 0; 
    k = l; 
    LL res=0;
    while (i < n1 && j < n2){
        if (L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
            res+=n1 - i;
        }
        k++;
    }
    while (i < n1){
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2){
        arr[k] = R[j];
        j++;
        k++;
    }
    return res;
}

LL mergeSort(LL arr[], int l, int r) {
    LL res=0;
    if (l < r) {
        int m = l+(r-l)/2;
        res+=mergeSort(arr, l, m);
        res+=mergeSort(arr, m+1, r);
        res+=merge(arr, l, m, r);
    }
    return res;
}
int main(){
    FAST
    BEGIN{
        int n;
        cin>>n;
        LL a[n];
        FOR(i,0,n)  cin>>a[i];
        cout<<mergeSort(a,0,n-1)<<endl;
    }
}*/
/*
int a[100];
int n,k,s,dem=0;
bool chuaxet[100],check=false;

void Try(int sum, int dem){
	if(check==true) return;
	if(dem==k){
		check=true;
		return;
	}
	REP(i, 1, n){
		if(chuaxet[i]==false){
			chuaxet[i]=true;
			if(sum==s){
				Try(0,dem+1);
				return;
			}
			if(sum>s) return;
			else Try(sum+a[i],dem);
		}
		chuaxet[i]=false;
	}
}
int main(){
	FAST
    BEGIN {
		cin>>n>>k;
		s=0;
		check=false;
		REP(i,1,n){
			cin>>a[i];
			chuaxet[i]=false;
			s+=a[i];
		}
		if(s%k!=0) cout<<0;
		else {
			s/=k;
			Try(0,0);
			if(check==true) cout<<1;
			else cout<<0;
		}
		cout<<"\n";
	}
	return 0;
}*/
/*
int main(){
    FAST
    BEGIN {
        int n,m;
        cin>>n>>m;
        int a[n+1][m+1];
        REP(i,1,n){
            REP(j,1,m)
                cin>>a[i][j];
        }
        int dp[n][m];
        dp[1][1]=a[1][1];
        REP(i,1,n){
            REP(j,1,m){
                if(i==1&&j==1);
                else if(i==1)    dp[i][j]=a[i][j]+dp[i][j-1];
                else if(j==1)    dp[i][j]=a[i][j]+dp[i-1][j];
                else dp[i][j]=a[i][j]+min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]));                
            }
        }
        cout<<dp[n][m]<<endl;
    }return 0;  
}*/

int main(){
    FAST
    BEGIN{
        int n,m;
        cin>>n>>m;
        int a[n+1][m+1];
        int dp[n+1][m+1];
        REP(i,1,n){
            REP(j,1,m){
                cin>>a[i][j];
                dp[i][j]=a[i][j];
            }
        }
        int res=0;
        REP(i,1,n){
            REP(j,1,m){
                if(a[i][j]==1){
                    if(a[i-1][j-1]==1&&a[i][j-1]==1&&a[i-1][j]==1)
                        dp[i][j]=min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+1;
                    res=max(dp[i][j],res);
                }           
            }
        }
        cout<<res<<endl;
    }
}
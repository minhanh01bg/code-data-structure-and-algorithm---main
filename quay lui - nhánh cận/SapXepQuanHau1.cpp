#include<stdio.h>
#include<math.h>
int a[20];
bool Ok(int x2,int y2){
    for(int i = 1; i < x2 ;i++)
        if(a[i] == y2 || abs(i-x2) == abs(a[i] - y2) )
            return false;
    return true;
}
int x;
void Xuat(int n){
    x++;
}
 
void Try(int i,int n){
    for(int j = 1;j<=n;j++){
        
        if(Ok(i,j)){
            a[i] = j;
            if(i==n) Xuat(n);
            Try(i+1,n);
        }
    }
}
 
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        x=0;
        int n ;
        scanf("%d",&n);
        Try(1,n);
        printf("%d\n",x);
    }
    
    return 0;
}
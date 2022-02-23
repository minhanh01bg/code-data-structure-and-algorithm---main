#include <stdio.h>
int n, k;
int th[17];
void in () {
    for (int i=1; i<=k; i++) {
        if(th[i]==1)
            printf ("A");
        if(th[i]==2)
            printf ("B");
        if(th[i]==3)
            printf ("C");
        if(th[i]==4)
            printf ("D");
        if(th[i]==5)
            printf ("E");
        if(th[i]==6)
            printf ("F");
        if(th[i]==7)
            printf ("G");
        if(th[i]==8)
            printf ("H");
        if(th[i]==9)
            printf ("I");
        if(th[i]==10)
            printf ("J");
        if(th[i]==11)
            printf ("K");
        if(th[i]==12)
            printf ("L");
        if(th[i]==13)
            printf ("M");
        if(th[i]==14)
            printf ("N");
        if(th[i]==15)
            printf ("O");
        if(th[i]==16)
            printf ("P");
        
    }
    printf("\n");
}

void Try(int i){
	for(int j=th[i-1]+1;j<=n-k+i;j++){
		th[i]=j;
		if(i==k){
			in();
		}
		else Try(i+1);
	}
}

int main () {
    int t;
    scanf("%d",&t);
    while(t--){
        scanf ("%d%d", &n, &k);
        Try(1);
    }   
    return 0;
}
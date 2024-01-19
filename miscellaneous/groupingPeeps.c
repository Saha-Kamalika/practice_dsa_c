#include <stdio.h>
void main(){
    int p, i;
    scanf("%d",&p);
    if(p>=100 && p<=200){
        int rem= p%4;
        int quo= p/4;
        for(i=1; i<=4; i++){
            if(i==1 || i==2 || i==3) printf("%d\n", quo);
            else printf("%d\n", quo+rem);
        }
    }
    else printf("INVALID INPUT");
}
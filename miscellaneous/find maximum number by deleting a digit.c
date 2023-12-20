//brute force
#include<stdio.h>

void convert(int n,int digi[]){
    for(int i=3;i>=0;i--){
        digi[i]=n%10;
        n/=10;
    }
}
int findMinIdx(int dig[]){
    int min=0;
    for(int i=1;i<4;i++){
        if(dig[i]<dig[min]) min=i;
    }
    return min;
}
int maximum(int dig[],int min){
    int res=0;
    for(int i=0;i<4;i++){
        if(i!=min){
            res=res*10+dig[i];
        }
    }
    return res;
}
void main(){
    int n=7895,dig[4];
    convert(n,dig);
    int minId=findMinIdx(dig);
    int ans=maximum(dig,minId);
    printf("%d",ans);
}

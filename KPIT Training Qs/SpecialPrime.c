#include <stdio.h>
int isPrime(int n){
    for(int i=2;i*i<=n;i++){
        if(n%i==0) return 0;
    }
    return 1;
}
int findIndex(int *arr, int len, int n){
    for(int i=0;i<len;i++){
        if(arr[i]==n) return i;
    }
    return -1;
}
int findSP(int *arr, int len){
    for(int i=0;i<len;i++){
        for(int j=0;j<len;j++){
            if(isPrime(arr[i]+arr[j])){
                if(findIndex(arr, len, arr[i]+arr[j])>0) return findIndex(arr, len, arr[i]+arr[j]); 
            }
        }
    }
    return -1;
}
void main(){
    int arr[]={5,3,8,10,7,12,13,17};
    int len=sizeof(arr)/sizeof(arr[0]);
    int res= findSP(arr, len);
    printf("%d",res);
}

//print the sum of the prime numbers in an array except the last prime number
#include <stdio.h>
int isprime(int n){
    int flag=0;
    if(n<2) return 0;
    for(int i=2;i<=n/2;i++){
        if(n%i==0){
            flag=1;
            break;
        }
    }
    if(flag==0) return 1;
    else return 0;
}
int main()
{
    int a[]={10,20,30,40};
    int n=sizeof(a)/sizeof(a[0]);
    int temp=0,temp1=0,sum=0,sume=0,c=0;
    for(int i=0;i<n;i++){
        if(isprime(a[i])){
            c++;
            sum+=a[i];
            if(temp<a[i]) temp=a[i];
        }
        else{ 
            sume+=a[i];
            if(temp1<a[i]) temp1=a[i];
        }
    }
    if(c!=0) printf("%d",sum-temp);
    if(c==0) printf("%d",sume-temp1);
    return 0;
}

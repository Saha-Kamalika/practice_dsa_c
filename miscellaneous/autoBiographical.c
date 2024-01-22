#include <stdio.h> 
int main(void){
    char n[20];
    gets(n);
    int l=0, count=0;
    while(n[l]!='\0'){
        l++;
    }
    int f[10]= {0};
    for(int i=0; i<l; i++){
        f[n[i]-'0']++;
    }
    for(int i=0; i<l; i++){
        if(f[i]!=(n[i]-'0')){
            printf("%d", 0);
            exit(0);
        }
    }
    for(int i=0;i<=9;i++){
        if(f[i]>0) count++;
    }
    printf("%d", count);
}

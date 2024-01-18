#include <stdio.h>
const int m=4;
const int n=4;
void convert(int a[m][n],int m,int n){
    int i, j;
    for(i=0;i<m;i++){
        for(j=i+1;j<n;j++){
            a[i][j]=0;
        }
    }
    printf("Converted matrix is: \n");
    for(i=0;i<m;i++){
        printf("\n");
        for(j=0;j<n;j++){
            printf("%d ",a[i][j]);
        }
    }
}
void main(){
    int a[m][n];
    int i, j;
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    convert(a,m,n);
}
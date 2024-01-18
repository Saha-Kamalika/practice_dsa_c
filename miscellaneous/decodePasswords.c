#include <stdio.h>
#include <math.h>
#include <string.h>
void main(){
    char s[]="PLEASESAVEME";
    int length= strlen(s);
    int row= floor(sqrt(length));
    int col= ceil(sqrt(length));
    char mat[row][col];
    //printf("%d%d", row, col);
    int i, j, k=0;
    for(i=0; i<row; i++){
        for(j=0; j<col; j++){
            mat[i][j]= s[k++];
        }
    }
    k=0;
    char ans[50];
    for(j=0; j<col; j++){
        for(i=0; i<row; i++){
            ans[k++]= mat[i][j];
        }
        ans[k++]=' ';
    }
    ans[k-1]='\0';
    printf("%s", ans);
}
#include<stdio.h>
#define number
#define mynum 10
int main(void){
    int num;
    printf("---displaying the number---");
    #ifdef number
    num=2;
    #else 
    printf("Enter the number: ");
    scanf("%d",&num);
    #endif
    printf("%d", num);
    int res=mynum*2;
    #undef mynum
    printf("\nMynum is %d",res);
}
/*
#include
#define
#undef
#ifdef
#ifndef
#if
#else
#endif
*/

#include <stdio.h>
//Passing array to a function
//approach 1
void fun1(int *a){
    for(int i=0;i<3;i++)
        printf("%d ",*(a+i)); //*a[i]
    printf("\n");
}
//approach 2
void fun2(int **a){ //pointer to a pointer
    for(int i=0;i<3;i++)
        printf("%d ",*(*(a+i))); //*a[i]
}
int main(void) {
    int a[]={10,20,30};
    fun1(a);
    int *ptr[3]; //
    for(int i=0;i<3;i++)
        ptr[i]=&i[a];//&a[i] (a+i) (i+a)
    fun2(ptr); 
    return 0;
}

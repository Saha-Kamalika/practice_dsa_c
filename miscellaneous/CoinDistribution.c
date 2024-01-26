//find no of 1Ru, 2Ru and 5Ru coins
#include <stdio.h>
int main(void){
    int n;
    scanf("%d",&n);
    int one=0, two=0;
    int five=(n-4)/5;
    if((n-five*5)%2==0) one=2;
    else one=1;
    two=(n-5*five-one)/2;
    printf("%d ",(one+two+five));
    printf("%d ",one);
    printf("%d ",two);
    printf("%d ",five);
}

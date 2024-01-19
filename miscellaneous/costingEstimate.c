#include<stdio.h>
int main(void){
    int interior= 18, exterior= 12;
    int inwalls, exwalls;
    float insq, exsq, totalCost=0.0;
    scanf("%d", &inwalls);
    scanf("%d", &exwalls);
    if(inwalls<0 || exwalls<0) printf("INVALID INPUT");
    else if(inwalls==0 && exwalls==0) printf("Total estimated cost: 0.0 INR");
    else{
        for(int i=0;i<inwalls;i++){
            scanf("%f", &insq);
            totalCost+= (interior*insq);
        }
        for(int i=0;i<exwalls;i++){
            scanf("%f", &exsq);
            totalCost+= (exterior*exsq);
        }
        printf("Total estimated cost: %.1f INR", totalCost);
    }
}
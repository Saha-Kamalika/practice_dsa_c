#include<stdio.h>
#define size 10
struct SymbolDecoder{
	char symbol;
	int value;
};
int decodeSymbol(struct SymbolDecoder symbols[], int n, char symbolToDecode){
	int i;
	for(i=0;i<n;i++){
		if(symbols[i].symbol==symbolToDecode) return symbols[i].value;
	}
	return -1;
}
int main(void){
	struct SymbolDecoder symbols[size];
	int n,i;
	printf("Enter the number of symbols: ");
	scanf("%d",&n);
	printf("Enter the mystical symbols and their corresponding numeric values: \n");
	for(i=0;i<n;i++){
		printf("Mystical Symbol %d: ",i+1);
		scanf(" %c",&symbols[i].symbol);
		printf("Numeric Value %d: ",i+1);
		scanf("%d",&symbols[i].value);
	}
	char symbolToDecode;
	printf("Enter the mystical symbol to decode: ");
	scanf(" %c",&symbolToDecode);
	int res=decodeSymbol(symbols,n,symbolToDecode);
	printf("The numeric value of the mystical symbol %c is %d",symbolToDecode,res);
}

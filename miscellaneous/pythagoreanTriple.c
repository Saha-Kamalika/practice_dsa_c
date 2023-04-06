#include<stdio.h>
int check(int x,int y,int z){
	int a,b,c;
	a=max(x,max(y,z));
	if(a==x){
		b=y;
		c=z;
	}
	else if(a==y){
		b=x;
		c=z;
	}
	else {
		b=x;
		c=y;
	}
	if (a*a==b*b+c*c)
		return 1;
	else return 0;
}
int max(int x,int y){
	if(x>y) return x;
	else return y;
}
void main(){
	int x,y,z;
	printf("Enter the 3 integers: ");
	scanf("%d%d%d",&x,&y,&z);
	if(check(x,y,z)) printf("Its a pythagorean triple");
	else printf("Its not a pythagorean triple");
}
//A Pythagorean Triplet is a set of three positive integers (say x, y, z) such that x^2 + y^2 = z^2

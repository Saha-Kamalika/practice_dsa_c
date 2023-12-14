// single row keyboard
#include <stdio.h>
#include<string.h>
#include<stdlib.h>
int calculate(char* key, char* word){
    int ind[26]={0};
    
    for(int i=0;i<26;i++)
        ind[key[i]-'a']=i;
        
    int prev=0,res=0;
    for(int i=0;i<strlen(word);i++){
        res+=abs(prev-ind[word[i]-'a']);
        
        prev=ind[word[i]-'a'];
    }
    return res;
}
int main() {
    char s[]="abcdefghijklmnopqrstuvwxyz";
    char word[]="cba";
    printf("%d",calculate(s,word));
    return 0;
}

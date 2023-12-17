#include<bits/stdc++.h>
using namespace std;
string findStatus(string& s){
    string ans="";
    int n=s.size();
    for(int i=n-1;i>=0;i--){
        if(s[i]==';') break;
        ans=s[i]+ans;
    }
    return ans;
}
int main(){
    string s="returned;in-transit";
    cout<<findStatus(s)<<endl;
}
